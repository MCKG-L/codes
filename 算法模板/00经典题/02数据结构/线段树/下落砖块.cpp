#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10,inf = 1e18;
/* 题目来源：abc_382_f
在一张H*W大小的地图（从上到下，从左到右坐标值增大）中有n个砖头，每个砖头的纵为r，左端点横坐标为c，长度为l
现在所有砖头垂直下落，如果一个砖头下面有其他砖头阻挡，则不可以下落,问最终稳定之后，每个砖头的纵坐标是多少？
地面的坐标为H 1 <= c <= W、1 <= r <= H、H,W <= 2e5

按照纵坐标从大到小考虑，该砖块最终所在的高度，取决于其下面最高的砖的高度,即坐标的最小值
使用线段树维护每个横坐标的高度最小值，对于砖头ai，ans[i]=seg.ask(a[i].c,a[i].c+a[i].l-1)
维护时：rangemodify(a[i].c,a[i].c+a[i].l-1,{ans[i],true})
注意这里使区间查询最小值 + 区间赋值
*/
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