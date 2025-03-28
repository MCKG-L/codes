#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
struct Node{
    int l,r;
    int l1,l2,r1,r2;
    int add;
    bool st = false;
}tr[N<<2];
char s[N];
int n,q;
void pushup(Node &U,Node &L,Node &R){
    U.l1 = L.l1,U.r1 = R.r1;
    if(L.l2 == -1) U.l2 = R.l1;
    else U.l2 = L.l2;
    if(R.r2 == -1) U.r2 = L.r1;
    else U.r2 = R.r2;
    if(L.r2 == R.l1 || L.r1 == R.l1 || L.r1 == R.l2) U.st = true;
    else U.st = false;
    // if(L.st || R.st) U.st = 1;
    U.st |= L.st | R.st;
}
void pushup(int u){
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void cal(int &x,int k){
    x = (x + k) % 26;
}
void cal(Node &U,int x){
    cal(U.l1,x),cal(U.l2,x);
    cal(U.r1,x),cal(U.r2,x);
}
void pushdown(int u){
    if(!tr[u].add) return;
    cal(tr[u<<1],tr[u].add);cal(tr[u<<1|1],tr[u].add);
    tr[u<<1].add = (tr[u<<1].add + tr[u].add) % 26;
    tr[u<<1|1].add = (tr[u<<1|1].add + tr[u].add) % 26;
    tr[u].add = 0;
}
void build(int u,int l,int r){
    tr[u] = {l,r};
    if(l == r){
        tr[u] = {l,r,s[l]-'a',-1,s[l]-'a',-1,0,false};
    }else{
        int mid = l + r >> 1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int l,int r,int x){
    if(tr[u].l >= l && tr[u].r <= r){
        cal(tr[u],x);
        tr[u].add  = (tr[u].add + x) % 26;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,x);
        if(r > mid) modify(u<<1|1,l,r,x);
        pushup(u);
    }
}
Node query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u];
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    Node ans,L,R;
    if(l <= mid) L = query(u<<1,l,r);
    if(r > mid) R = query(u<<1|1,l,r);
    pushup(ans,L,R);
    if(l <= mid && r > mid) return ans;
    else if(l <= mid) return L;
    else return R;
}
void solve(){
    cin >> n >> q;
    cin >> s + 1;
    build(1,1,n);
    while(q--){
        int op,l,r;
        cin >> op >> l >> r;
        if(op == 1){
            int x;cin >> x;
            // x = x % 26;
            modify(1,l,r,x);
        }else{
            cout << (query(1,l,r).st ? "NO" : "YES") << endl;
        }
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}