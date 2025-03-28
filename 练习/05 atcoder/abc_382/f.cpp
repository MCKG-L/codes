#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10,inf = 1e18;
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
    int add;
    bool put = false;
    void apply(const Tag &t){ //懒标记传递
        if(t.put){
            put = t.put;
            add = t.add;
        }
    }
};
int Max;
struct Info { 
    int mn = Max;
    void apply(const Tag &t) {// 懒标记apply
        if(t.put) mn = t.add;
    }
};
Info operator+(const Info &ls,const Info &rs) { //由子节点更新父节点
    Info u;
    u.mn = min(ls.mn,rs.mn);
    return u;
}
// -------------------------------
struct Node{
    int r,c,l;
    bool operator<(const Node &p)const{
        return r > p.r;
    }
};
void solve(){
    int h,w,n;
    cin >> h >> w >> n;
    vector<Node> a(n + 1);
    for(int i=1;i<=n;i++){
        int r,c,l;
        cin >> r >> c >> l;
        a[i] = {r,c,l};
    }
    // sort(a.begin()+1,a.begin()+1+n);
    Max = h + 1;//初始化最小值
    vector<int> ans(n + 1);
    vector<int> order(n);//技巧 对下标排序
    iota(order.begin(),order.end(),1);
    sort(order.begin(),order.end(),[&](int i,int j){return a[i].r > a[j].r;});
    LazySegTree<Info,Tag> seg(w);
    for(auto i : order){
        auto [r,c,l] = a[i];
        ans[i] = seg.ask(c,c+l-1).mn - 1;
        seg.rangemodify(c,c+l-1,{ans[i],true});
    }
    for(int i=1;i<=n;i++) cout << ans[i] << endl;
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