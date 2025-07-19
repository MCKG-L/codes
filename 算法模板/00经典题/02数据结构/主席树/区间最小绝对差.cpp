#include <bits/stdc++.h>
#define pc(c) putchar(c)
#define rep(a,b,c) for (int a = (b) ; a < (c) ; ++a)
#define endl '\n'

using namespace std;
using ll = long long ;
using ai2 = array<int,2> ;
/*
给定一个长度为 n 的整数序列 a1,a2,…,an
请你回答 Q个询问。
每个询问给定一个区间 [l,r]
，请你找到一个可能的整数 x，使得 ∑i=lr(|x−ai|) 的值尽可能小，并输出这个最小可能值。
*/
/*
可以证明x取[l,r]中的中位数时，绝对差之和最小
需要统计小于x的个数以及小于x的权值之和，区间权值之和
*/
const int maxn = 1e5 + 10,maxm = maxn * 21;
int n ;
int a[maxn] ;   // 存读入的数
int rt[maxn],idx,len;   // rt 主席树的根数组，len 离散化后数的个数
vector<int> vec ; // 用于离散化的数组
struct node {   // 节点
    ll val = 0;     // 子树和
    int sz = 0,ls = 0,rs = 0 ; // 子树大小，左子节点，右子节点
    node operator+(const node &other) {
        node res ;
        res.val = val + other.val ;
        res.sz = sz + other.sz ;
        return res ;
    }
    node operator-(const node &other) {
        node res ;
        res.val = val - other.val ;
        res.sz = sz - other.sz ;
        return res ;
    }
}tr[maxm] ;

inline int add(int p,int l,int r,int id) {  // 插入节点
    int q = ++ idx ;
    tr[q] = tr[p] ;
    ++ tr[q].sz ;
    tr[q].val += vec[id]; 
    if (l ^ r){
        int mid = l + r >> 1;
        if (id <= mid) tr[q].ls = add(tr[p].ls,l,mid,id) ;
        else tr[q].rs = add(tr[p].rs,mid + 1,r,id) ; 
    }
    return q; 
}
inline int get_k(int p,int q,int l,int r,int k) {   // 主席树求区间第k大
    p = rt[p - 1],q = rt[q] ;  
    int mid,sz ;
    while (l ^ r) {
        mid = l + r >> 1 ;
        sz = tr[tr[q].ls].sz - tr[tr[p].ls].sz ;    // 左子树的大小
        if (sz < k) k -= sz,q = tr[q].rs,p = tr[p].rs,l = mid + 1; // 如果左子树的大小小于k就往右走  
        else q = tr[q].ls,p = tr[p].ls,r = mid ;    // 往左走
    }
    return vec[l];  // 最后的l就是第k大节点
}
inline node presum(int L,int R,int id) {    // 求一个前缀信息和，即树中小于等于vec[id]的节点的信息
    int p = rt[L - 1],q = rt[R] ;
    int l = 1,r = len ;
    node ret ;
    while (l <= r && id >= l) {
        if (l == r) {
            ret = ret + tr[q] - tr[p] ;
            return ret ;
        }
        int mid = l + r >> 1;
        if (id >= mid) 
            ret = ret + tr[tr[q].ls] - tr[tr[p].ls],l = mid + 1,q = tr[q].rs,p = tr[p].rs ;
        else 
            r = mid,q = tr[q].ls,p = tr[p].ls ;
    }
    return ret; 
}
inline int get(int x) {     // 求大于等于x的数
    return lower_bound(vec.begin(),vec.end(),x) - vec.begin() ;
}
inline int Get(int x) {     // 求小于等于x的数
    return upper_bound(vec.begin(),vec.end(),x) - vec.begin() - 1; 
}
inline ll solve(int L,int R) { // 对应[L,R]求答案
    ll s = tr[rt[R]].val - tr[rt[L - 1]].val ; // 整个区间的和
    int Len = R - L + 1;    // 区间长度
    ll x1 = get_k(L,R,1,len,Len / 2),x2 = get_k(L,R,1,len,Len / 2 + 1) ;// 这里不分奇偶都求了，反正不会tle
    node lt = presum(L,R,Get(x1)) ;     // 求小于等于 x1 的数的信息
    node ltt = presum(L,R,Get(x2)) ;    // 求小于等于 x2 的数的信息
    ll res = lt.sz * x1 - lt.val + (s - lt.val) - (Len - lt.sz) * x1;   // 以x1为中位数的答案
    ll res1 = ltt.sz * x2 - ltt.val + (s - ltt.val) - (Len - ltt.sz) * x2; // 以x2为中位数的答案
    return min(res,res1) ;      //取最小值
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1 ;
    rep(test,1,T + 1){
        cin >> n ;
        vec.push_back(-2e9) ;   // 加入头部哨兵，让离散化的值从1开始
        rep(i,1,n + 1) cin >> a[i],vec.push_back(a[i]) ; 
        rt[0] = ++ idx ;
        sort(vec.begin(),vec.end()) ;
        vec.erase(unique(vec.begin(),vec.end()),vec.end()) ; // 离散化
        len = vec.size() - 1;
        for (int i = 1 ; i <= n ; ++ i) 
            rt[i] = add(rt[i - 1],1,len,get(a[i])) ; // 建树
        int q ;
        cin >> q ;
        while (q --) {
            int l,r ;
            cin >> l >> r; 
            cout << solve(l,r) << endl ;
        }
    }

    return 0;
}