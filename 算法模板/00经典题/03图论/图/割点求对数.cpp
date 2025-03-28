#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,inf = 1e18;
/* luogu P3469
给一张联通的无向图，问将将点i去掉之后，有多少点对(x,y)满足x和y不联通

求割点的过程中进行计数
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> siz(n + 1,0),dfn(n + 1,0),low(n + 1,0),ans(n + 1,0);
    vector<bool> mask(n + 1,false);
    int ts = 0;
    auto dfs = [&](auto dfs,int u,int fa,int root)->void{
        dfn[u] = low[u] = ++ ts;
        siz[u] = 1;
        int cnt = 0,sum = 0;
        for(auto v : g[u]){
            if(dfn[v] == 0){
                cnt ++;
                dfs(dfs,v,u,1);
                siz[u] += siz[v];
                low[u] = min(low[u],low[v]);
                if(low[v] >= dfn[u]){
                    ans[u] += siz[v] * (n - siz[v]);
                    sum += siz[v];
                    mask[u] = 1;
                }
                if(u != root && cnt > 1) mask[u] = 1;
            }else low[u] = min(low[u],dfn[v]);
        }
        if(mask[u]) ans[u] += (n - 1) + (sum + 1) * (n - sum - 1);
        else ans[u] = 2 * (n - 1);
    };
    dfs(dfs,1,0,1);
    for(int i=1;i<=n;i++) cout << ans[i] << endl;
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