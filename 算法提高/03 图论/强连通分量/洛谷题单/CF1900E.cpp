#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 2e5 + 10;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> w(n + 1);
    vector<vector<int>> a(n + 1);
    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    vector<int> dfn(n + 1),low(n + 1),id(n + 1);
    vector<int> siz(n + 1),c(n + 1),stk(n + 10),instk(n + 1);
    int ts = 0,top = 0,scc_cnt = 0;
    auto dfs = [&](auto &dfs,int u)->void{
        dfn[u] = low[u] = ++ ts;
        stk[++top] = u;instk[u] = 1;
        for(auto v : a[u]){
            if(!dfn[v]){
                dfs(dfs,v);
                low[u] = min(low[u],low[v]);
            }else if(instk[v]){
                low[u] = min(low[u],dfn[v]);
            }
        }
        if(dfn[u] == low[u]){
            int y;
            scc_cnt ++;
            do{
                y = stk[top--];
                instk[y] = 0;
                c[scc_cnt] += w[y];
                siz[scc_cnt] ++;
                id[y] = scc_cnt;
            }while(y != u);
        }
    };
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) dfs(dfs,i);
    }
    vector<vector<int>> ne(scc_cnt + 1);
    vector<int> ind(scc_cnt + 1);
    for(int i=1;i<=n;i++){
        for(auto v : a[i]){
            int x = id[i],y = id[v];
            if(x != y) ne[x].push_back(y),ind[y] ++;
        }
    }
    vector<int> ans(scc_cnt + 1),res(scc_cnt + 1,inf);
    int Max = -1,s = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(ind[i] == 0){
            ans[i] = siz[i],res[i] = c[i];
            if(ans[i] > Max){
                Max = ans[i];
                s = res[i];
            }else if(ans[i] == Max){
                s = min(s,res[i]);
            }
        }
    }
    for(int i=scc_cnt;i>=1;i--){
        for(auto v : ne[i]){
            if(ans[i] + siz[v] > ans[v]){
                ans[v] = ans[i] + siz[v];
                res[v] = res[i] + c[v];
            }else if(ans[i] + siz[v] == ans[v]){
                res[v] = min(res[v],res[i] + c[v]);
            }
        }
        if(ans[i] > Max){
            Max = ans[i];
            s = res[i];
        }else if(ans[i] == Max){
            s = min(s,res[i]);
        }
    }
    cout << Max << ' ' << s << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}