# 树状数组
``` cpp
struct FenWick{
    std::vector<int> tr;
    FenWick(int n){
        tr.resize(n+1,0);
    }
    void add(int x,int c){
        for(int i=x;i<tr.size();i+=i&-i) tr[i] += c;
    }
    int ask(int x){
        int ans = 0;
        for(int i=x;i>=1;i-=i&-i) ans += tr[i];
        return ans;
    }
    int ask(int l,int r){
        return get(r) - get(l-1);
    }
};
```
# 树状数组--full
``` cpp
template <typename T>
struct Fenwick {
    int n;
    vector<T> w;
    Fenwick(int n) {
        this->n = n;
        w.resize(n + 1);
    }
    void add(int x, T k) {
        for (; x <= n; x += x & -x) {
            w[x] += k;
        }
    }
    void add(int x, int y, T k) { // 区间修改
        add(x, k), add(y + 1, -k);
    }
    T ask(int x) {  //单点查询
        auto ans = T();
        for (; x; x -= x & -x) {
            ans += w[x];
        }
        return ans;
    }
    T ask(int x, int y) { // 区间查询(区间和)
        return ask(y) - ask(x - 1);
    }
    int kth(T k) { //查找第k大的值
        int ans = 0;
        for (int i = __lg(n); i >= 0; i--) {
            int val = ans + (1 << i);
            if (val < n && w[val] < k) {
                k -= w[val];
                ans = val;
            }
        }
        return ans + 1;
    }
};
``` 
# 普通线段树
``` cpp
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
    void modify(int u, int st, int ed, int pos, const Info &v) {
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
        else if (r <= mid)res = ask(u * 2, st, mid, l, r);
        else if (l > mid)res = ask(u * 2 + 1, mid + 1, ed, l, r);
        return res;
    }
    Info ask(int l,int r){
        return ask(1,1,n,l,r);
    }
    void modify(int pos,Info v){
        modify(1,1,n,pos,v);
    }
};
struct Info { //注意初值问题,不会默认赋初值
    
};
Info operator+(Info ls, Info rs){
	Info u = Info();

	return u;
}
```
# 懒标记线段树
``` cpp
//不带build，记得初始化节点（区间端点信息等）
template<class Info, class Tag>
struct LazySegTree {
    // u是节点编号 l r是操作区间 st ed是节点区间
    int n;
    vector<Info> info;
    vector<Tag> tag;
    LazySegTree(int n) {
        this->n = n;
        tag.resize(4 * n + 10);
        info.resize(4 * n + 10);
    }
    void pushup(int u) {
        info[u] = info[u<<1] + info[u<<1|1];
    }
    void apply(int u, const Tag& v) {
        info[u].apply(v);
        tag[u].apply(v);
    }
    void pushdown(int u) {
        apply(u<<1, tag[u]);
        apply(u<<1|1, tag[u]);
        tag[u] = Tag();
    }
    void modify(int u, int pos,int st, int ed, const Info& v) {
        if (st == ed) {
            info[u] = v; return;
        }
        int mid = (st + ed) / 2;
        pushdown(u);
        if (pos <= mid) modify(u<<1, pos, st, mid, v);
        if (pos > mid) modify(u<<1|1, pos, mid + 1, ed, v);
        pushup(u);
    }
    void modify(int pos, const Info& v) {
        modify(1, pos, 1, n, v);
    }
    Info ask(int u, int l, int r, int st, int ed) {
        if (st >= l && ed <= r) {
            return info[u];
        }
        int mid = (st + ed) / 2;
        Info res = {};
        pushdown(u);
        if (l <= mid && r > mid) {
            res = ask(u<<1, l, r, st, mid) + ask(u<<1|1, l, r, mid + 1, ed);
        }
        else if (l <= mid) {
            res = ask(u<<1, l, r, st, mid);
        }
        else {
            res = ask(u<<1|1, l, r, mid + 1, ed);
        }
        return res;
    }
    Info ask(int l, int r) {
        return ask(1, l, r, 1, n);
    }
    void rangemodify(int u, int l, int r, int st, int ed, const Tag& v) {
        if (st >= l && ed <= r) {
            apply(u, v); return;
        }
        int mid = (st + ed) / 2;
        pushdown(u);
        if (l <= mid) rangemodify(u<<1, l, r, st, mid, v);
        if (r > mid) rangemodify(u<<1|1, l, r, mid + 1, ed, v);
        pushup(u);
    }
    void rangemodify(int l, int r, const Tag& v) {
        rangemodify(1, l, r, 1, n, v);
    }
};
//----------重写-----------------
struct Tag { //懒标记信息
    
    void apply(const Tag &t){ //懒标记传递
        
    }
};
struct Info { //线段树维护的信息
    
    void apply(const Tag &t) {// 懒标记apply
        
    }
};
Info operator+(const Info &ls,const Info &rs) { //由子节点更新父节点
    Info u;
    
    return u;
}
// -------------------------------

void init(){
    for(int i=1;i<=n;i++){
        seg.modify(i,{x,i,i}) //初始化节点区间信息
    }
}
// ---------区间赋值 区间最值-----------
struct Tag { //懒标记信息
    int add = 0;
    bool put = false;
    void apply(const Tag &t){ //懒标记传递
        if(t.put){
            put = t.put;
            add = t.add;
        }
    }
};
struct Info { //线段树维护的信息
    int mx = 0;
    void apply(const Tag &t) {// 懒标记apply
        if(t.put) mx = t.add;
    }
};
Info operator+(const Info &ls,const Info &rs) { //由子节点更新父节点
    Info u;
    u.mx = max(ls.mx,rs,mx);
    return u;
}
// -----------区间修改 区间和---------
struct Tag { //懒标记信息
    int add;
    void apply(const Tag &t){ //懒标记传递
        add += t.add;
    }
};
struct Info { //线段树维护的信息
    int sum,l,r;
    void apply(const Tag &t) {// 懒标记apply
        sum += t.add * (r - l + 1);
    }
};
Info operator+(const Info &ls,const Info &rs) { //由子节点更新父节点
    Info u;
    u.l = ls.l,u.r = rs.r;
    u.sum = ls.sum + rs.sum;
    return u;
}


// ---------区间修改 区间最值-----------
struct Tag { //懒标记信息
    int add;
    void apply(const Tag &t){ //懒标记传递
        add += t.add;
    }
};
struct Info { //线段树维护的信息
    int mx;
    void apply(const Tag &t) {// 懒标记apply
        mx += t.add;
    }
};
Info operator+(const Info &ls, const Info &rs) { //由子节点更新父节点
    Info u;
    u.mx = max(ls.mx,rs.mx);
    return u;
}

```

# ST表 RMQ
``` cpp
// 求区间最大值、最小值、区间&、区间|、区间gcd、区间lcm
// 基于倍增 预处理nlog(n) 查询O(1)
template<class T>
struct RMQ { //传入数组[0~n-1] 查询下表[1~n]
	int n;
	vector<T>a;
	vector<array<T, 21>> f;
	function<T(T, T)> func;
	RMQ() {};
	vector<int> len;
	void work(vector<T> a,function<T(T, T)> func_) { //传入lmbda表达式
		this->a = a;
		this->func = func_;
		n = a.size();
		f.assign(n+1, {});
		len.resize(n + 1);
		len[1] = 0;
		for (int i = 2; i <= n; i++) len[i] = len[i / 2] + 1;//求log2(i)
		for (int i = 1; i <= n; i++) f[i][0] = a[i-1];
		const int lg = log2(n);
		for (int j = 1; j <= lg; j++) {
			for (int i = 1; i + (1 << (j)) - 1 <= n; i++) {
				f[i][j] = func(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
			}
		}
		return;
	}
	T ask(int l, int r) {
		return func(f[l][len[r - l + 1]], f[r - (1 << len[r - l + 1]) + 1][len[r - l + 1]]);
	}
};
```
# 并查集
``` cpp
// 数字范围[1,n]
struct DSU{
    std::vector<int> f,siz;
    DSU(int n):f(n+1),siz(n+1,1){std::iota(f.begin(),f.end(),0);}
    int find(int x){
        while(f[x] != x) x = f[x] = f[f[x]];
        return x;
    }
    void unite(int a,int b){
        a = find(a),b = find(b);
        if(a == b) return;
        f[b] = a;
        siz[a] += siz[b];
    }
    bool same(int a,int b){
        return find(a) == find(b);
    }
    int size(int x){
        return siz[find(x)];
    }
};
```
# 带权并查集-异或
``` cpp
// 带权并查集--判断环的边权异或值是否为0
struct DSU
{
    vector<int> f, fv;
    int find(int x)
    {
        if (f[x] == x)
            return x;
        int xx = find(f[x]);
        fv[x] ^= fv[f[x]];
        f[x] = xx;
        return xx;
    }
    DSU(int n)
    {
        f.resize(n + 10);
        fv.resize(n + 10);
        for (int i = 1; i <= n; i++)
            f[i] = i;
    }
    int merge(int x, int y, int w)
    {
        int u = x;
        int v = y;
        x = find(x);
        y = find(y);
        if (x == y)
        {
            if ((fv[u] ^ fv[v] ^ w) == 0)
                return 1;
            else
                return -1;
        }
        f[x] = y;
        fv[x] = fv[u] ^ fv[v] ^ w;
        return 2;
    }
};
```

# 缩点SCC
``` cpp
struct SCC{ // [1,n]
    vector<vector<int>> g, scc;//g是原图 scc存储每个强连通分量
    vector<int> dfn, low, stk, id; //id[i] 点i所属的强连通分量编号
    vector<bool> ins;
    int ts, n,scc_cnt;
    SCC(const vector<vector<int> > &g) : g(g){
        n = (int)g.size();
        dfn.assign(n, 0);
        low.assign(n, 0);
        id.assign(n, -1);
        ins.assign(n, false);
        stk.reserve(n);
        scc.push_back({});
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
```
# tarjan求割点
``` cpp
//适用于有向图求割点
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
        int cnt = 0;
        for(auto v : g[u]){
            if(!dfn[v]){
                tarjan(v,u,root);
                low[u] = min(low[u],low[v]);
                if(low[v] >= dfn[u]){
                    cnt += 1;
                    if(x != root || cnt > 1) mask[u] = true;
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
```
# 矩阵快速幂
``` cpp
int matlen; //矩阵的长度
struct matrix { // [1,n]
    using i64 = long long;
    i64 a[60][60];
    matrix(){
        memset(a,0,sizeof(a));
    }
	matrix operator*(matrix x) {
        matrix ans=matrix(); 
        for(int i=1;i<=matlen;i++){
            for(int j=1;j<=matlen;j++){
                for(int k=1;k<=matlen;k++){
                    ans.a[i][j]+=a[i][k]*x.a[k][j]%mod;
                    ans.a[i][j]%=mod;
                }
            }
        }
        return ans;
 	}
    matrix operator^(int b){
        matrix ans=matrix();
        for(int i=1;i<=matlen;i++){
            ans.a[i][i]=1;
        }
        matrix base=*this;
        while(b){
            if(b&1)ans=ans*base;
            b>>=1; base=base*base;
        }
        return ans;
    }
};
```

# 树链剖分（求LCA）
``` cpp
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
```
# 树链剖分(+线段树)
``` cpp
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
    int mx = 0;
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
```