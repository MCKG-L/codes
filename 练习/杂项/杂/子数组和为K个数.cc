#include <iostream>
#include <map>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
ll a[N];
map<ll,ll> mp;
int main()
{
    ll n,k;cin >> n >> k;
    ll ans = 0;
    mp[0] = 1;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
        ans += mp[a[i]-k];
        mp[a[i]]++;
    }
    cout << ans;
    return 0;
}