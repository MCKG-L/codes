#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
int dep[N],fa[N][20],F[30];
/*
fa[u][i]表示 从u点开始向上跳2^i步后到达的节点
*/
vector<vector<int>> a(N);
int n,q,r;
void dfs(int u,int father){
    dep[u] = dep[father] + 1;
    fa[u][0] = father;
    for(int i=1;i<20;i++) fa[u][i] = fa[fa[u][i-1]][i-1];
    for(auto v : a[u]){
        if(v == father) continue;
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(dep[u] < dep[v]) swap(u,v);
    //跳到同一层
    for(int i=19;~i;i--){
        if(dep[fa[u][i]] >= dep[v]){
            u = fa[u][i];
        }
    }
    if(u == v) return v;
    //跳到LCA的下一层
    for(int i=19;~i;i--){
        if(fa[u][i] != fa[v][i]){
            u = fa[u][i],v = fa[v][i];
        }
    }
    return fa[u][0];
}
void solve(){
    cin >> n >> r >> q;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(r,0);
    F[1] = 1,F[2] = 2;
    for(int i=3;i<30;i++) F[i] = F[i-1] + F[i-2];
    while(q--){
        vector<int> g;
        int x,k;
        cin >> x >> k;
        if(k >= 25 || x + F[k] > n){
            cout << 0 << endl;
            continue;
        }
        while(x + F[k] <= n) g.push_back(x + F[k ++]);
        int ans = g[0];
        for(auto v : g) ans = lca(ans,v);
        cout << ans << endl;
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
