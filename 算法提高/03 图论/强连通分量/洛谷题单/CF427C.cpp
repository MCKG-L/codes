#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;

void solve(){
    int n;cin >> n;
    vector<int> w(n + 1);
    for(int i=1;i<=n;i++) cin >> w[i];
    int m;cin >> m;
    vector<vector<int>> a(n + 1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    vector<int> dfn(n + 1),low(n + 1),Min(n + 1,inf),cnt(n + 1);
    int ts = 0,top = 0;
    vector<int> stk(n + 10),instk(n + 1);
    int idx = 0;
    auto tarjan = [&](auto &tarjan,int u)->void{
        dfn[u] = low[u] = ++ ts;
        stk[++top] = u;instk[u] = 1;
        for(auto v : a[u]){
            if(!dfn[v]){
                tarjan(tarjan,v);
                low[u] = min(low[u],low[v]);
            }else if(instk[v]) low[u] = min(low[u],dfn[v]);
        }
        if(dfn[u] == low[u]){
            int y;
            idx ++;
            do{
                y = stk[top--];
                instk[y] = 0;
                if(w[y] < Min[idx]){
                    Min[idx] = w[y];
                    cnt[idx] = 1;
                }else if(w[y] == Min[idx]){
                    cnt[idx] ++;
                }
            }while(y != u);
        }
    };
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(tarjan,i);
    }
    int ans = 0,res = 1;
    for(int i=1;i<=idx;i++){
        ans += Min[i];
        res  = res * cnt[i] % mod;
    }
    cout << ans << ' ' << res << endl;
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