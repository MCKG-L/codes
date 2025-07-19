#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 2e5 + 10;
/*
洛谷 P3810
有 n 个元素，第 i 个元素有 ai​,bi​,ci​ 三个属性，
设 f(i) 表示满足 aj​≤ai​ 且 bj​≤bi​ 且 cj​≤ci​ 且 j=i 的 j 的数量。
对于 d∈[0,n)，求 f(i)=d 的数量。
*/
struct BIT{
    vector<int> tr;
    int n;
    void init(int n){
        this->n = n;
        tr.assign(n + 10,0);
    }
    void add(int x,int c){
        while(x <= n){
            tr[x] += c;
            x += x & -x;
        }
    }
    int ask(int x){
        int res = 0;
        while(x){
            res += tr[x];
            x -= x & -x;
        }
        return res;
    }
}BIT;
struct Node{
    int a,b,c,cnt;
    int res;
    bool operator<(const Node &p)const{
        if(b != p.b) return b < p.b;
        return c < p.c;
    }
    bool operator!=(const Node &p)const{
        return !(a == p.a && b == p.b && c == p.c);
    }
}q[N],nq[N];
void CDQ(int l,int r){
    if(l == r) return;
    int mid = (l + r) / 2;
    CDQ(l,mid),CDQ(mid+1,r);
    sort(nq+l,nq+mid+1);
    sort(nq+mid+1,nq+r+1);
    int i = l,j = mid + 1;
    while(j <= r){
        while(i <= mid && nq[i].b <= nq[j].b){
            BIT.add(nq[i].c,nq[i].cnt);
            i ++;
        }
        nq[j].res += BIT.ask(nq[j].c);
        j ++ ;
    }
    for(int k=l;k<i;k++) BIT.add(nq[k].c,-nq[k].cnt);
}
void solve(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        q[i] = {a,b,c};
    }
    int m = 0,cnt = 0;
    sort(q+1,q+n+1,[&](Node &p1,Node &p2){
        if(p1.a != p2.a) return p1.a < p2.a;
        if(p1.b != p2.b) return p1.b < p2.b;
        return p1.c < p2.c;
    });
    for(int i=1;i<=n;i++){
        cnt ++;
        if(q[i] != q[i+1]){
            auto [a,b,c,_,__] = q[i];
            m ++;
            nq[m].a = a;
            nq[m].b = b;
            nq[m].c = c;
            nq[m].cnt = cnt;
            nq[m].res = 0;
            cnt = 0;
        }
    }
    BIT.init(k);
    CDQ(1,m);
    vector<int> res(n + 1);
    for(int i=1;i<=m;i++){
        res[nq[i].res + nq[i].cnt - 1] += nq[i].cnt;
    }
    for(int i=0;i<n;i++) cout << res[i] << '\n';
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
