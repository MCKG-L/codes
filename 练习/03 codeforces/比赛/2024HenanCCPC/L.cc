#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<ll> dp(m + 10);
    vector<ll> a(m+1);
    for(int i=1;i<=m;i++) cin >> a[i];
    dp[0] = 0,dp[1] = a[1] + 1;
    for(int i=2;i<=m;i++){
        dp[i] = dp[i-1] + 1 + a[i];
        for(int j=1;j<=30&&i-j>=1;j++){
            dp[i] = min(dp[i],dp[i-j-1] + a[i] + (ll)pow(j + 1,4));
        }
    }
    cout << dp[m] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}