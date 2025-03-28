#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
#define int long long
using namespace std;
const int N = 5e5 + 10;
/*
一个数列的最大公约数和其差分数列的最大公约数相同
利用差分数组，转化为单点修改，区间查询的问题，可以用线段树维护区间最大公约数
用树状数组维护前缀和
Q l r -> ans = gcd(a[l],gcd([l+1~r]));
*/
int n,m;
struct Node{
    int l,r;
    int sum,d;
}tr[N<<2];
int a[N];
int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}
void pushup(Node &u,Node &l,Node &r){
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d,r.d);
}
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r){
    tr[u].l = l,tr[u].r = r;
    if(l == r){
        int d = a[l] - a[l-1];
        tr[u] = {l,r,d,d};
    }else{
        int mid = l + r >> 1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int x,int v){
    if(tr[u].l == x && tr[u].r == x){
        int d = tr[u].d;
        tr[u] = {x,x,d+v,d+v};
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}
Node query(int u,int l,int r){

    if(tr[u].l >= l && tr[u].r <= r) return tr[u];
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid) return query(u<<1,l,r);
        else if(l > mid) return query(u<<1|1,l,r);
        else{
            Node L = query(u<<1,l,r),R = query(u<<1|1,l,r);
            Node res;
            pushup(res,L,R);
            return res;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    while(m--){
        string op;int l,r;
        cin >> op >> l >> r;
        if(op == "Q"){
            Node L = query(1,1,l),R = query(1,l+1,r);
            cout << abs(gcd(L.sum,R.d)) << endl;
        }else{
            int d;cin >> d;
            modify(1,l,d);
            if(r + 1 <= n) modify(1,r+1,-d);
        }
    }
    return 0;
}
