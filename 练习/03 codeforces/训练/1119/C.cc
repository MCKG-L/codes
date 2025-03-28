#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n+1),dp(n+1,-INF);
    for(int i=1;i<=n;i++) cin >> a[i];
    dp[1] = a[1];
    for(int i=2;i<=n;i++){
        dp[i] = a[i];
        if((a[i] & 1) ^ (a[i-1] & 1)) dp[i] = max(dp[i],dp[i-1]+a[i]);
    }
    int ans = -INF;
    for(int i=1;i<=n;i++) ans = max(ans,dp[i]);
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}