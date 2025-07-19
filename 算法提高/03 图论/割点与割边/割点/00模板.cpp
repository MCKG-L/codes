#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,inf = 1e18;
/*无向图求割点

*/
struct DCC{
    vector<int> dfn,low;
    vector<int> mask;
    vector<vector<int> >g;
    int n,ts;
    DCC(const vector<vector<int>> &g):g(g){
        this->n = (int)g.size();
        this->ts = 0;
        dfn.assign(n,0);
        low.assign(n,0);
        mask.assign(n,false);
        build();
    }
    void tarjan(int u,int fa,int root){
        dfn[u] = low[u] = ++ ts;
        int cnt = 0;//u的子树个数
        for(auto v : g[u]){
            if(!dfn[v]){
                cnt += 1;//为了处理u为根的情况
                tarjan(v,u,root);
                low[u] = min(low[u],low[v]);//回溯值
                if(low[v] >= dfn[u]){
                    if(u != root || cnt > 1) mask[u] = true;
                }
            }else low[u] = min(low[u],dfn[v]);//v能走到u的祖先节点
        }
    }
    void build(){
        for(int i=1;i<n;i++){
            if(!dfn[i]) tarjan(i,-1,i);
        }
    }
};
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
    DCC dcc(g);
    vector<int> ans;
    for(int i=1;i<=n;i++) if(dcc.mask[i]) ans.push_back(i);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << ' ';
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