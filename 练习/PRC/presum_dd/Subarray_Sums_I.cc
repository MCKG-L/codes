// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// int main()
// {
//     int n,x;cin >> n >> x;
//     map<ll,int> mp;
//     ll a[n+1] = {};
//     ll ans = 0;
//     mp[0] = 1;
//     for(int i=1;i<=n;i++){
//         cin >> a[i];
//         a[i] += a[i-1];
//         ans += mp[a[i]-x];
//         mp[a[i]]++;
//     }
//     cout << ans;
//     return 0;
// }
//快慢指针法
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n,x;
    cin >> n >> x;
    ll a[n+1] = {};
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    int l = 0,r = 1;
    ll ans = 0;
    while(l!=n){
        while(a[r] - a[l] < x) r++;
        if(a[r] - a[l] == x) ans++;
        l++;
    }
    cout << ans;
    
    return 0;
}