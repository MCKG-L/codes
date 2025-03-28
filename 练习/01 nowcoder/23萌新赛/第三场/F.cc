#include <iostream>
using namespace std;
typedef unsigned long long ll;
const int mod = 998244353;
ll qmi(ll a,ll b){
    ll ans = 1ll;
    while(b){
        if(b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
int main()
{
    ll n,x;
    cin >> n >> x;
    if(x == 1){
        cout << qmi(2,(2*n+1)%mod) << endl;
        return 0;
    }
    ll ans = qmi(x%mod,qmi(2,n+1)) - 1;
    ans = (ans * qmi(x-1,mod-2)) % mod;
    cout << ans << endl;
    return 0;
}