#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 1e5 + 10,mod = 998244353,inf = 1e18;
/*
树链剖分 + 线段树，求树上任意两点之间路径中边权的最大值
经典用法是求任意两点之间路径经过的点权信息，将边权信息存储在深度较大的节点上可以转化问题
亦可以求路径和
*/
int siz[N],id[N],top[N],son[N],dep[N],fa[N],ts;
int n,m;
vector<vector<int>> a(N);
void dfs1(int u,int f){
    dep[u] = dep[f] + 1;fa[u] = f;
    siz[u] = 1;
    for(auto v : a[u]){
        if(v == f) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v]) son[u] = v;
    }
}
void dfs2(int u,int t){
    id[u] = ++ts;
    top[u] = t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(auto v : a[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v,v);
    }
}
template<class Info>
struct SegmentTree {
    vector<Info>tree;
    int n;
    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n + 10);
    }
    SegmentTree() {}
	void init(int n){
		this->n = n;
        tree.resize(4 * n + 10);
	}
    void modify(int u, int st, int ed, int pos, const Info v) {
        if (st == ed) {
            tree[u] = v;
            return;
        }
        int mid = (st + ed) / 2;
        if (pos <= mid) modify(u * 2, st, mid, pos, v);
        if (pos > mid) modify(u * 2 + 1, mid + 1, ed, pos, v);
        tree[u] = tree[u * 2] + tree[u * 2 + 1];
    }
    Info ask(int u, int st, int ed, int l, int r) {
        if (st >= l && ed <= r) {
            return tree[u];
        }
        int mid = (st + ed) / 2;
        Info res = Info();
        if (l <= mid && r > mid) {
            res = ask(u * 2, st, mid, l, r) + ask(u * 2 + 1, mid + 1, ed, l, r);
        }
        else if (r <= mid) res = ask(u * 2, st, mid, l, r);
        else if (l > mid) res = ask(u * 2 + 1, mid + 1, ed, l, r);
        return res;
    }
    Info ask(int l, int r) {
        return ask(1, 1, n, l, r);
    }
    void modify(int pos, Info u) {
        modify(1, 1, n, pos, u);
    }
};
struct Info {
    int mx;
};
Info operator+(Info ls, Info rs){
	Info u = Info();
    u.mx = max(ls.mx,rs.mx);
	return u;
}
void solve(){
    cin >> n >> m;
    vector<array<int,3>> q(n - 1);
    for(int i=1;i<=n-1;i++){
        int u,v;cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        q[i-1] = {u,v,i};
    }
    SegmentTree<Info> seg(n);
    dfs1(1,0);
    dfs2(1,1);
    for(auto [u,v,c] : q){
        if(dep[u] > dep[v]) swap(u,v);
        //将边权映射到深度较大的端点上
        seg.modify(id[v],{c});
    }
    vector<int> pre(m + 2);
    auto query = [&](int u,int v)->int{
        int ans = 0;
        while(top[u] != top[v]){
            if(dep[top[u]] < dep[top[v]]) swap(u,v);
            ans = max(ans,seg.ask(id[top[u]],id[u]).mx);
            u = fa[top[u]];
        }
        if(u == v) return ans;
        if(dep[u] > dep[v]) swap(u,v);
        //注意 这里是id[son[u]],因为节点存储的是与其父节点的边权
        ans = max(ans,seg.ask(id[son[u]],id[v]).mx);
        return ans;
    };
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        pre[query(u,v)] ++;
    }
    for(int i=1;i<=n-1;i++) pre[i] += pre[i-1],cout << pre[i] << ' ';
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