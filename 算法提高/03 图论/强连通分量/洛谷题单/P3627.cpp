#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,inf = 1e18;
struct SCC{ // [1,n]
    vector<vector<int>> g, scc;//g是原图 scc存储每个强连通分量
    vector<int> dfn, low, stk, id; //id[i] 点i所属的强连通分量编号
    vector<bool> ins;
    vector<int> w,hw;
    int ts, n,scc_cnt;
    SCC(const vector<vector<int> > &g,const vector<int> &hs) : g(g),hw(hs){
        n = (int)g.size();
        dfn.assign(n, 0);
        low.assign(n, 0);
        id.assign(n, -1);
        ins.assign(n, false);
        stk.reserve(n);
        scc.push_back({});
        w.assign(n,0);
        ts = 0,scc_cnt = 0;
        build();
    }
    void tarjan(int u){
        dfn[u] = low[u] = ++ts;
        stk.push_back(u);
        ins[u] = 1;
        for(auto j : g[u]){
            if (!dfn[j]){
                tarjan(j);
                low[u] = min(low[u], low[j]);
            }
            else if (ins[j]) low[u] = min(low[u], dfn[j]);
        }
        if (dfn[u] == low[u]){
            scc.push_back({});
            scc_cnt += 1;
            int y;
            do{
                y = stk.back();
                stk.pop_back();
                id[y] = scc_cnt;
                ins[y] = 0;
                w[scc_cnt] += hw[y];
                scc.back().push_back(y);
            }while(y != u);
        }
    }
    void build(){
        for(int i = 1; i < n; i++){
            if (!dfn[i]){
                tarjan(i);
            }
        }
    }
};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vector<int> w(n + 1);
    for(int i=1;i<=n;i++) cin >> w[i];
    int S,P;
    cin >> S >> P;
    vector<int> p(P);
    for(int i=0;i<P;i++) cin >> p[i];
    SCC scc(g,w);
    int s = scc.scc_cnt;
    vector<vector<int>> a(s + 1);
    vector<int> dis(s + 1,0);
    for(int i=1;i<=n;i++){
        for(auto v : g[i]){
            int x = scc.id[i],y = scc.id[v];
            if(x != y){
                a[x].push_back(y);
            }
        }
    }
    dis[scc.id[S]] = scc.w[scc.id[S]];
    int ans = -1;
    for(int i=scc.id[S];i>=1;i--){
        for(auto v : a[i]){
            dis[v] = max(dis[v],dis[i] + scc.w[v]);
        }
    }
    for(auto x : p) ans = max(ans,dis[scc.id[x]]);
    cout << ans << endl;
    // queue<int> q;
    // q.push(scc.id[S]);
    // dis[scc.id[S]] = scc.w[scc.id[S]];
    // while(q.size()){
    //     auto k = q.front();q.pop();
    //     for(auto v : a[k]){
    //         dis[v] = max(dis[v],dis[k] + scc.w[v]);
    //         q.push(v);
    //     }
    // }
    // int ans = -1;
    // for(auto x : p) ans = max(ans,dis[scc.id[x]]);
    // cout << ans << endl;
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