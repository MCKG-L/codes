#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
typedef pair<int,int> PII;
int dp[N][10];
int a[N],n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        string s = to_string(a[i]);
        int l = s[0]-'0',r = s[s.size()-1]-'0';
        for(int j=0;j<10;j++) dp[i][j] = dp[i-1][j];
        dp[i][r] = max(dp[i][r],dp[i-1][l] + 1);
    }
    int ans = 0;
    for(int i=0;i<10;i++) ans = max(ans,dp[n][i]);
    cout << n - ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}