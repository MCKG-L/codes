#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
using ll = long long;
void solve(){
    int n,k;
    cin >> n >> k;
    map<int,int> mp;
    mp[0] = 1;
    ll ans = 0,sum = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        sum += x;
        ans += mp[sum%k];
        mp[sum%k] ++;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) solve();
    return 0;
}