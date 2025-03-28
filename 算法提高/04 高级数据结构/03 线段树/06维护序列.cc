#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
#define endl '\n'
/*
存在两个懒标记
*/
using namespace std;
const int N = 1e5 + 10;
int n,p,m;
struct Node{
    int l,r;
    int sum,add,mul;
}tr[N<<2];
int a[N];
void pushup(int u){
    tr[u].sum = (tr[u<<1].sum + tr[u<<1|1].sum)%p;
}
void eval(Node &u,int add,int mul){
    u.sum = (u.sum * mul + (u.r-u.l+1)*add) % p;
    u.add = (u.add * mul + add) % p;
    u.mul = u.mul * mul % p;
}
void pushdown(int u){
    eval(tr[u<<1],tr[u].add,tr[u].mul);
    eval(tr[u<<1|1],tr[u].add,tr[u].mul);
    tr[u].add = 0,tr[u].mul = 1;
}
void build(int u,int l,int r){
    tr[u] = {l,r,0,0,1};
    if(l == r){
        tr[u].sum = a[l];
    }else{
        int mid = l + r >> 1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int l,int r,int add,int mul){
    if(tr[u].l >= l && tr[u].r <= r){
        eval(tr[u],add,mul);
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,add,mul);
        if(r > mid) modify(u<<1|1,l,r,add,mul);
        pushup(u);
    }
}
int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int ans = 0;
        if(l <= mid) ans = query(u<<1,l,r);
        if(r > mid) ans = (ans + query(u<<1|1,l,r))%p;
        return ans;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> p;
    for(int i=1;i<=n;i++) cin >> a[i];
    // int m;cin >> m;
    build(1,1,n);
    while(m--){
        int op,l,r;
        cin >> op >> l >> r;
        if(op == 1){
            int d;cin >> d;
            modify(1,l,r,0,d);
        }else if(op == 2){
            int d;cin >> d;
            modify(1,l,r,d,1);
        }else{
            cout << query(1,l,r) << endl;
        }
    }
    return 0;
}