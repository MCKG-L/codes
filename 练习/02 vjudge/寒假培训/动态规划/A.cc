#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
using ll = long long;
//通用模板 (a^k)%p
ll qmi(ll a,ll k,ll p){
    ll ans = 1;
    while(k){
        if(k & 1) ans = ans * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return ans;
}
int main()
{
    ll n,p;
    cin >> n >> p;
    int a[n+1] = {};
    for(int i=1;i<=n;i++) cin >> a[i];
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans *= (qmi(p,a[i],mod)%mod+1);
        ans = ans % mod;
    }
    cout << ans;
    return 0;
}
