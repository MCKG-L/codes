#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
/*求无向图的割点 P3388

*/
int dfn[N],low[N],ts;
bool cut[N];
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    auto tarjan = [&](auto &tarjan,int u,int root)->void{
        dfn[u] = low[u] = ++ ts;
        int cnt = 0;
        for(auto v : a[u]){
            if(!dfn[v]){
                tarjan(tarjan,v,root);
                low[u] = min(low[u],low[v]);
                if(low[v] >= dfn[u]){
                    cnt ++;
                    if(u != root || cnt > 1) cut[u] = 1;
                }
            }else{ //访问过
                low[u] = min(low[u],dfn[v]);
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(tarjan,i,i);
    }
    vector<int> ans;
    for(int i=1;i<=n;i++) if(cut[i]) ans.push_back(i);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << ' ' ;
    cout << endl;
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
