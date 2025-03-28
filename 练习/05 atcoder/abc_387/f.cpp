#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll;
struct SCC{ 
    vector<vector<int> > g, scc;
    vector<int> dfn, low, stk, id;
    vector<bool> ins;
    int ts, n,scc_cnt;
    SCC(const vector<vector<int> > &g) : g(g){
        n = (int)g.size();
        dfn.assign(n, 0);
        low.assign(n, 0);
        id.assign(n, -1);
        ins.assign(n, false);
        stk.reserve(n);
        ts = 0;
        scc.push_back({});
        build();
    }
    //栈中元素的含义是强连通分量中的点
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
        if (dfn[u] == low[u]){ //一个强连通分量中的最低点（时间戳最小的点）
            scc.push_back({});
            scc_cnt ++;
            int y;
            do{
                y = stk.back();
                stk.pop_back();
                id[y] = scc_cnt;
                ins[y] = 0;
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
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        g[x].push_back(i);
    }
    SCC scc(g);
    int s = scc.scc_cnt;
    vector<vector<int>> a(s + 1);
    vector<int> ind(s + 1);
    for(int i=1;i<=n;i++){
        for(auto j : g[i]){
            int u = scc.id[i],v = scc.id[j];
            if(u != v){
                a[u].push_back(v);
                ind[v] ++;
            }
        }
    }
    vector<vector<int>> dp(s+1,vector<int>(m + 1,1));
    auto dfs = [&](auto dfs,int u)->void{
        for(auto v : a[u]){
            dfs(dfs,v);
            int sum = 0;
            for(int i=1;i<=m;i++){
                sum = (sum + dp[v][i]) % mod;
                dp[u][i] = (dp[u][i] * sum) % mod;
            }
        }
    };
    int ans = 1;
    for(int i=1;i<=s;i++){
        if(ind[i] == 0){
            dfs(dfs,i);
            int sum = 0;
            for(int j=1;j<=m;j++) sum = (sum + dp[i][j]) % mod;
            ans = ans * sum % mod;
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