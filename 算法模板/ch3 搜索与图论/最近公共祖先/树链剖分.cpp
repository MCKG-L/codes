#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
typedef pair<int,int> PII;
int fa[N],siz[N],son[N],dep[N],top[N];
int n,q;
int d[N];//差分数组-树上差分
vector<vector<int>> a(N);
void dfs1(int u,int father){
    dep[u] = dep[father] + 1,siz[u] = 1,fa[u] = father;
    for(auto v : a[u]){
        if(v == father) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v]) son[u] = v;
    }
}
void dfs2(int u,int t){
    top[u] = t;//t为所在重链的链头
    if(son[u] == 0) return;
    //搜重儿子
    dfs2(son[u],t);
    //搜轻儿子
    for(auto v : a[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v,v);
    }
}
int lca(int u,int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
void solve(){
    cin >> n >> q;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs1(1,0);dfs2(1,1);
    while(q--){
        int u,v;
        cin >> u >> v;
        int c = lca(u,v);
        d[c] --,d[u] ++;
        d[fa[c]] --,d[v] ++;
    }
    int ans = 0;
    function<int(int,int)> dfs = [&](int u,int father)->int{
        int cnt = 0;
        for(auto v : a[u]){
            if(v == father) continue;
            cnt += dfs(v,u);
        }
        d[u] += cnt;
        ans = max(ans,d[u]);
        return d[u];
    };
    dfs(1,0);
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
