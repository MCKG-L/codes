#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 3e18;
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
struct Tag { //懒标记信息
    int add;
    void apply(Tag t){ //懒标记传递
        add += t.add;
    }
};
struct Info { //线段树维护的信息
    int mx;
    void apply(Tag t) {// 懒标记apply
        mx += t.add;
    }
};
Info operator+(Info ls, Info rs) { //由子节点更新父节点
    Info u;
    u.mx = max(ls.mx,rs.mx);
    return u;
}
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1),pre(n+1),suf(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    {
        vector<int> st(n + 1,false);
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(!st[a[i]]) cnt ++;
            pre[i] = cnt;
            st[a[i]] = true;
        }
    }
    {
        vector<int> st(n + 1,false);
        int cnt = 0;
        for(int i=n;i>=1;i--){
            if(!st[a[i]]) cnt ++;
            suf[i] = cnt;
            st[a[i]] = true;
        }
    }
    LazySegTree<Info,Tag> seg(n);
    int ans = 0;
    vector<int> lst(n + 1,-1);
    for(int i=1;i<n;i++){
        if(~lst[a[i]]){
            seg.rangemodify(lst[a[i]],i-1,{1});
        }
        ans = max(ans,pre[i]+suf[i+1]+seg.ask(1,i).mx);
        lst[a[i]] = i;
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