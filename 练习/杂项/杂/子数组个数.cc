#include <iostream>
#include <map>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
map<ll,int> mp;
ll ans = 0;
ll a[N];
int main()
{
    int n,x;cin >> n >> x;
    mp[0] = 1;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
        ans += mp[a[i] - x];
        mp[a[i]]++;
    }
    cout << ans;
    return 0;
}