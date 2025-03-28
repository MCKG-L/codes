#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10;
int a[N],tr1[N],tr2[N];
int n,m;
int lowbit(int x){
    return x & -x;
}
void add(int tr[],int x,int c){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}
int get(int tr[],int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)) res += tr[i];
    return res;
}
int sum(int x){
    return (x+1)*get(tr1,x)-get(tr2,x);
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        add(tr1,i,a[i]-a[i-1]);
        add(tr2,i,(a[i]-a[i-1])*i);
    }
    while(m--){
        string op;cin >> op;
        if(op == "C"){
            int l,r,c;cin >> l >> r >> c;
            add(tr1,l,c);add(tr1,r+1,-c);
            add(tr2,l,l*c);add(tr2,r+1,-(r+1)*c);
        }else{
            int l,r;cin >> l >> r;
            int ans = sum(r) - sum(l-1);
            cout << ans << endl;
        }
    }
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}