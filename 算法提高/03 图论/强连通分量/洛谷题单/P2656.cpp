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
    vector<vector<array<int,3>>> a(n + 1);
    for(int i=0;i<m;i++){
        int u,v,s;
        double r;
        cin >> u >> v >> s >> r;
        int t = s,nr = r * 10;
        int tot = 0;
        while(s){
            tot += s;
            s = s * nr / 10;
        }
        a[u].push_back({v,t,tot});
    }
    vector<int> dfn(n + 1),low(n + 1);
    vector<int> stk(n + 10),instk(n + 1),id(n + 1);
    int ts = 0,top = 0;
    vector<vector<int>> scc;
    auto dfs = [&](auto &dfs,int u)->void{
        dfn[u] = low[u] = ++ ts;
        stk[++top] = u,instk[u] = 1;
        for(auto [v,s,tot] : a[u]){
            if(!dfn[v]){
                dfs(dfs,v);
                low[u] = min(low[u],low[v]);
            }else if(instk[v]) low[u] = min(low[u],dfn[v]);
        }
        if(dfn[u] == low[u]){
            int y;
            scc.push_back({});
            do{
                y = stk[top--];
                instk[y] = 0;
                id[y] = scc.size();
                scc.back().push_back(y);
            }while(y != u);
        }
    };
    for(int i=1;i<=n;i++){
        if(!dfn[i]) dfs(dfs,i);
    }
    int scc_cnt = scc.size();
    vector<int> w(scc_cnt + 1),ind(scc_cnt + 1);
    vector<vector<PII>> ne(scc_cnt + 1);
    for(int i=1;i<=n;i++){
        for(auto [v,s,tot] : a[i]){
            int x = id[i],y = id[v];
            if(x == y){
                w[x] += tot;
            }else{
                ind[y] ++;
                ne[x].push_back({y,s});
            }
        }
    }
    vector<int> dp(scc_cnt + 1);
    int s;cin >> s;
    dp[id[s]] = w[id[s]];
    int ans = w[id[s]];
    for(int i=id[s];i>=1;i--){
        for(auto [v,c] : ne[i]){
            // cerr << i << ' ' << v << ' ' << c << endl;
            dp[v] = max(dp[v],dp[i] + c + w[v]);
            ans = max(ans,dp[v]);
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}
