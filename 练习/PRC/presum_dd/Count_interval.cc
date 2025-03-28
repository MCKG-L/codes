#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll n,k;cin >> n >> k;
    ll a[n+1] = {};
    map<ll,ll> mp;
    ll ans = 0;
    mp[0] = 1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
        ans += mp[a[i]-k];
        mp[a[i]]++;
    }
    cout << ans;
    return 0;
}