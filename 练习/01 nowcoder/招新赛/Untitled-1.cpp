#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
ll a[(int)1e6];
ll qmi(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans = (ans * a) % mod;
        }
        b >>= 1;
        a = (a * a) % mod;
 }
  return ans;
}
int main()
{
    ll t,n,p;cin >> t;
    while(t--){
        cin >> n >> p;
        for(int i=1;i<=n;i++) cin >> a[i];//先输入
        if(p == 1){
            cout << (n & 1) << endl;
            continue;
        }
        sort(a+1,a+n+1);
        ll ans = 0;
        for(int i=1;i<n;i++){
            ans += qmi(p,a[i]);
            ans %= mod;
        }
        ll max_ = qmi(p,a[n]);
        cout << ((max_-ans)%mod + mod) % mod << endl;
    }
    return 0;
}