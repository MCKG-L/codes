#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n,m,h;
    cin >> n >> m >> h;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(h+1,0x3f3f3f3f)));
    dp[1][1][h] = 0;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=h;k++){
                if(i - 1 > 0){
                    dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k]+1);
                    if(k + a[i][j] <= h){
                        dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k+a[i][j]]);
                    }
                }
                if(j - 1 > 0){
                    dp[i][j][k] = min(dp[i][j][k],dp[i][j-1][k] + 1);
                    if(k + a[i][j] <= h){
                        dp[i][j][k] = min(dp[i][j][k],dp[i][j-1][k+a[i][j]]);
                    }
                }
            }
        }
    }
    int ans = 1e9;
    for(int i=1;i<=h;i++){
        ans = min(ans,dp[n][m][i]);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}