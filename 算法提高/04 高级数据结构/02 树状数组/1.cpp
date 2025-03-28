#include <iostream>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define int long long
using namespace std;
const int N = 2e5 + 10;
int tr[N],n;
int a[N];
int M[N],L[N];
int lowbit(int x){
    return x & -x;
}
void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i)){
        tr[i] += c;
    }
}
int sum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i)) ans += tr[i];
    return ans;
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        int x = a[i];
        M[i] = sum(n) - sum(x);
        L[i] = sum(x-1);
        add(x,1);
    }
    memset(tr,0,sizeof tr);
    int ans1 = 0,ans2 = 0;
    for(int i=n;i;i--){
        int x = a[i];
        ans1 += M[i] * (sum(n)-sum(x));
        ans2 += L[i] * sum(x-1);
        add(x,1);
    }
    cout << ans1 << ' ' << ans2 << endl;
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