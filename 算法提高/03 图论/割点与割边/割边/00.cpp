#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
int dfn[N],low[N],ts;
vector<PII> bridge;
/*无向图求割边
可以处理重边和自环的情况
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<PII>> a(n + 1);
    int idx = 0;
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back({v,idx++});
        a[v].push_back({u,idx++});
    }
    auto tarjan = [&](auto &tarjan,int u,int e)->void{
        dfn[u] = low[u] = ++ ts;
        for(auto [v,id] : a[u]){
            if(!dfn[v]){
                tarjan(tarjan,v,id);
                low[u] = min(low[u],low[v]);
                if(low[v] > dfn[u]){
                    bridge.push_back({min(u,v),max(u,v)});
                }
            }else if(id != (e ^ 1)){
                low[u] = min(low[u],dfn[v]);
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(tarjan,i,-1);
    }
    sort(bridge.begin(),bridge.end());
    for(auto [x,y] : bridge){
        cout << x << ' ' << y << endl;
    }
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
