#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
//线段树模板题
struct Node{
    int l,r;
    int s0,s1;
    bool tag;
}tr[N<<2];
int n,q;
char s[N];
int a[N];
void pushup(int u){
    tr[u].s0 = tr[u<<1].s0 ^ tr[u<<1|1].s0;
    tr[u].s1 = tr[u<<1].s1 ^ tr[u<<1|1].s1;
}
void build(int u,int l,int r){
    tr[u] = {l,r};
    if(l == r){
        if(s[l] == '1') tr[u].s1 = a[l],tr[u].s0 = 0;
        else tr[u].s0 = a[l],tr[u].s1 = 0;
    }else{
        int mid = l + r >> 1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void pushdown(int u){
    if(tr[u].tag){
        swap(tr[u<<1].s0,tr[u<<1].s1);
        swap(tr[u<<1|1].s0,tr[u<<1|1].s1);
        tr[u<<1].tag ^= 1,tr[u<<1|1].tag ^= 1;
        tr[u].tag = 0;
    }
}
int query(int u,int l,int r,int g){
    if(tr[u].l >= l && tr[u].r <= r){
        if(g) return tr[u].s1;
        else return tr[u].s0;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int ans = 0;
        if(l <= mid) ans ^= query(u<<1,l,r,g);
        if(r > mid) ans ^= query(u<<1|1,l,r,g);
        return ans;
    }
}
void modify(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r){
        swap(tr[u].s0,tr[u].s1);
        tr[u].tag ^= 1;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r);
        if(r > mid) modify(u<<1|1,l,r);
        pushup(u);
    }
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    cin >> s + 1;
    build(1,1,n);
    cin >> q;
    while(q--){
        int op;cin >> op;
        if(op == 1){
            int l,r;cin >> l >> r;
            modify(1,l,r);
        }else{
            int g;cin >> g;
            cout << query(1,1,n,g) << ' ';
        }
    }
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}