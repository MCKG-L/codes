#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 1e5 + 10,mod = 998244353,inf = 1e18;
template<class Info>
struct SegmentTree{
    int n;
    vector<Info> tr;
    SegmentTree(int n){
        this->n = n;
        tr.assign(n * 4 + 10,Info());
    }
    SegmentTree(){};
    void modify(int u,int st,int ed,int pos,Info &v){
        if(st == ed){
            tr[u] = v;
            return;
        }
        int mid = (st + ed) / 2;
        if(pos <= mid) modify(u<<1,st,mid,pos,v);
        if(pos > mid) modify(u<<1|1,mid+1,ed,pos,v);
        tr[u] = tr[u<<1|1] + tr[u<<1];
    }
    void modify(int pos,Info v){
        modify(1,1,n,pos,v);
    }
    Info ask(int u,int st,int ed,int l,int r){
        if(l <= st && r >= ed) return tr[u];
        int mid = st + ed >> 1;
        Info res;
        if(l <= mid) res = ask(u<<1,st,mid,l,r);
        if(r > mid) res = res + ask(u<<1|1,mid+1,ed,l,r);
        return res;
    }
    Info ask(int l,int r){
        return ask(1,1,n,l,r);
    }
};
struct Info{
    int mx = 0;
};
Info operator+(Info ls, Info rs){
	Info u=Info();
    u.mx = max(ls.mx,rs.mx);
	return u;
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> siz(n + 1),son(n + 1),fa(n + 1),dep(n + 1),top(n + 1),id(n + 1);
    int ts = 0;
    vector<vector<int>> a(n + 1);
    vector<array<int,3>> q;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        q.push_back({u,v,i});
    }
    auto dfs1 = [&](auto dfs,int u,int f)->void{
        siz[u] = 1,fa[u] = f,dep[u] = dep[f] + 1;
        for(auto v : a[u]){
            if(v == f) continue;
            dfs(dfs,v,u);
            siz[u] += siz[v];
            if(siz[son[u]] < siz[v]) son[u] = v;
        }
    };
    dfs1(dfs1,1,0);
    auto dfs2 = [&](auto dfs2,int u,int tp)->void{
        top[u] = tp;id[u] = ++ ts;
        if(!son[u]) return;
        dfs2(dfs2,son[u],tp);
        for(auto v : a[u]){
            if(v == fa[u] || v == son[u]) continue;
            dfs2(dfs2,v,v);
        }
    };
    dfs2(dfs2,1,1);
    SegmentTree<Info> seg(n+1);
    
    for(int i=0;i<=n;i++) seg.modify(i,{0});
    for(auto [u,v,i] : q){
        if(dep[u] > dep[v]) swap(u,v);
        cout << id[v] << ' ' << i << endl;
        seg.modify(id[v],(Info){i});
    }
    cerr << seg.ask(5,5).mx << endl;
    auto query = [&](int u,int v)->int{
        int res = 0;
        while(top[u] != top[v]){
            if(dep[top[u]] < dep[top[v]]) swap(u,v);
            cout << id[top[u]] << ' ' << id[u] << endl;
            res = max(res,seg.ask(id[top[u]],id[u]).mx);
            u = fa[top[u]];
        }
        if(u == v) return res;
        if(dep[u] > dep[v]) swap(u,v);
        res = max(res,seg.ask(id[son[u]],id[v]).mx);
        return res;
    };
    vector<int> b(n);
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        cout << query(u,v) << ' ';
        b[query(u,v)] ++;
    }
    for(int i=1;i<n;i++){
        b[i] += b[i-1];
        cout << b[i] << ' ';
    }
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