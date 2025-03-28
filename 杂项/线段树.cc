#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
int n,m;
int a[N];
struct Node{
    int l,r;
    int sum,add;
}tr[N<<2];
void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}
void build(int u,int l,int r){
    tr[u].l = l,tr[u].r = r;
    if(l == r){
        tr[u] = {l,r,a[l],0};
    }else{
        int mid = l + r >> 1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void pushdown(int u){
    if(tr[u].add){
        Node &L = tr[u<<1],&R = tr[u<<1|1],&U = tr[u];
        L.add += U.add;L.sum += (L.r-L.l+1)*U.add;
        R.add += U.add;R.sum += (R.r-R.l+1)*U.add;
        U.add = 0;
    }
}
int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int sum = 0;
        if(l <= mid) sum += query(u<<1,l,r);
        if(r > mid) sum += query(u<<1|1,l,r);
        return sum;
    }
}
void modify(int u,int l,int r,int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += (tr[u].r-tr[u].l+1)*d;
        tr[u].add += d;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,d);
        if(r > mid) modify(u<<1|1,l,r,d);
        pushup(u);
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
            cout << query(1,l,r) << endl;
        }else{
            int d;cin >> d;
            modify(1,l,r,d);
        }
    }
    return 0;
}