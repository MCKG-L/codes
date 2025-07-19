#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 2100;
/*洛谷P4306 求有向图的联通数
度量一个有向图连通情况的一个指标是连通数，指图中可达顶点对个的个数。
SCC缩点，维护每个SCC中点的数目，缩点之后及建立反向图，
在拓扑序上维护每对点之间的可达性（bitset优化）
最后暴力统计 O(n^2)
*/
void solve(){
    int n;cin >> n;
    vector<vector<int>> a(n + 1);
    for(int i=1;i<=n;i++){
        string s;cin >> s;
        for(int j=1;j<=n;j++){
            if(s[j-1] == '1'){
                a[i].push_back(j);
            }   
        }
    }
    vector<int> dfn(n + 1),low(n + 1),siz(n + 1);
    vector<int> stk(n + 10),instk(n + 1),id(n + 1);
    int ts = 0,top = 0;
    vector<vector<int>> scc;
    auto dfs = [&](auto &dfs,int u)->void{
        dfn[u] = low[u] = ++ ts;
        stk[++top] = u,instk[u] = 1;
        for(auto v : a[u]){
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
                siz[scc.size()] ++;
                id[y] = scc.size();
                scc.back().push_back(y);
            }while(y != u);
        }
    };
    for(int i=1;i<=n;i++){
        if(!dfn[i]) dfs(dfs,i);
    }
    int scc_cnt = scc.size();
    bitset<N> bit[scc_cnt+1];
    for(int i=1;i<=scc_cnt;i++){
        bit[i][i] = 1;
    }
    vector<int> ind(scc_cnt + 1);
    vector<vector<int>> ne(scc_cnt + 1);
    for(int i=1;i<=n;i++){
        for(auto v : a[i]){
            int x = id[i],y = id[v];
            if(x != y){
                ind[x] ++;
                ne[y].push_back(x);
            }
        }
    }
    for(int i=1;i<=scc_cnt;i++){
        for(auto v : ne[i]){
            bit[v] |= bit[i];
        }
    }
    int ans = 0;
    for(int i=1;i<=scc_cnt;i++){
        for(int j=1;j<=scc_cnt;j++){
            if(bit[i][j]) ans += siz[i] * siz[j];
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
