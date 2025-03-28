#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 3e18;
/* 来源 abc_397_f
给定一个长度为n的序列A，把这个序列划分为三个连续的非空序列，记序列中不同元素的个数为
序列的权重，问划分后三个序列的权重之和最大是多少？

若划分为两个区间，则维护前缀数组和后缀数组，枚举每一个切分位置即可
现在考虑以i为分界点将原序列划分为[1,i]、[i+1,n]两个部分，[i+1,n]部分的权重可以使用后缀数组直接求得到
考虑如何将[1,i]部分划分为两个区间 假设以j为分界点划分为[1,j],[j+1,i]
发现对于区间[1,i]无论如何划分，其贡献至少为区间[1,i]中数的种数，只有在将两个相同的数分为两个区间
时才会造成额外贡献，所以只需要统计额外贡献即可，在某个数第一个出现的位置和最后一次出现的位置之间划分
都可以造成一个额外贡献，每个数造成的额外贡献是独立的，可以使用线段树维护区间加，查询得到的区间最大值即是
最大额外贡献值
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
        if(~lst[a[i]]) seg.rangemodify(lst[a[i]],i-1,{1});
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