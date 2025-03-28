#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
struct Node{
    int l,r;
    int sum;
    int lm,rm,tm;
}tr[N<<2];
int a[N],n,m;
void pushup(Node &u,Node &l,Node &r){
    u.sum = l.sum + r.sum;
    u.lm = max(l.lm,l.sum+r.lm);
    u.rm = max(r.rm,r.sum+l.rm);
    u.tm = max(max(l.tm,r.tm),l.rm+r.lm);
}
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r){
    tr[u] = {l,r};
    if(l == r) tr[u] = {l,r,a[l],a[l],a[l],a[l]};
    else{
        int mid = l + r >> 1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }

}
void modify(int u,int x,int y){
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x,x,y,y,y,y};
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u<<1,x,y);
        else modify(u<<1|1,x,y);
        pushup(u);
    }
}
Node query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if(r <= mid) return query(u<<1,l,r);
    else if(l > mid) return query(u<<1|1,l,r);
    else{
        Node L = query(u<<1,l,r);
        Node R = query(u<<1|1,l,r);
        Node ans;
        pushup(ans,L,R);
        return ans;
    }
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    while(m--){
        int op,x,y;
        cin >> op >> x >> y;
        if(op == 1){
            if(x > y) swap(x,y);
            cout << query(1,x,y).tm << endl;
        }else{
            modify(1,x,y);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}