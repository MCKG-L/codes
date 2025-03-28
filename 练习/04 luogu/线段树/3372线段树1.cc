#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
struct Node{
    int l,r;
    int sum;
    int add,mul;
}tr[N<<2];
int n,m,p;
int a[N];
void pushup(int u){
    tr[u].sum = (tr[u<<1].sum + tr[u<<1|1].sum) % p;
}
void pushdown(int u){
    tr[u<<1].sum = (tr[u<<1].sum * tr[u].mul + (tr[u<<1].r-tr[u<<1].l+1)*tr[u].add) % p;
    tr[u<<1|1].sum = (tr[u<<1|1].sum * tr[u].mul + (tr[u<<1|1].r-tr[u<<1|1].l+1)*tr[u].add) % p;
    tr[u<<1].add = tr[u<<1].add * tr[u].mul + tr[u].add;tr[u<<1].add %= p;
    tr[u<<1|1].add = tr[u<<1|1].add * tr[u].mul + tr[u].add;;tr[u<<1|1].add %= p;
    tr[u<<1].mul *= tr[u].mul;tr[u<<1].mul %= p;
    tr[u<<1|1].mul *= tr[u].mul;tr[u<<1|1].mul %= p;
    tr[u].add = 0;tr[u].mul = 1;
}
void build(int u,int l,int r){
    tr[u] = {l,r,0,0,1};
    if(l == r) tr[u].sum = a[l];
    else{
        int mid = l + r >> 1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int l,int r,int k,int ml){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum  = (tr[u].sum * ml + (tr[u].r-tr[u].l+1)*k) % p;
        tr[u].add = tr[u].add * ml + k;tr[u].add %= p;
        tr[u].mul *= ml;tr[u].mul %= p;
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        pushdown(u);
        if(l <= mid) modify(u<<1,l,r,k,ml);
        if(r > mid) modify(u<<1|1,l,r,k,ml);
        pushup(u);
    }
}
int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int ans = 0;
        if(l <= mid) ans += query(u<<1,l,r);
        if(r > mid) ans = (ans + query(u<<1|1,l,r)) % p;
        return ans;
    }
}
void solve(){
    cin >> n >> m >> p;
    for(int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    while(m--){
        int op,l,r;
        cin >> op >> l >> r;
        if(op == 1){
            int k;cin >> k;
            modify(1,l,r,0,k);
        }else if(op == 2){
            int k;cin >> k;
            modify(1,l,r,k,1);
        }else{
            cout << query(1,l,r) << endl;
        }
    }
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}