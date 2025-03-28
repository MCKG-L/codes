#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 310;
int dp[N][2*N],a[N][2*N];
int n,k;
void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=n-i+1;j<=n+i-1;j++){
            cin >> a[i][j];
        }
    }
    memset(dp,0x3f,sizeof dp);
    dp[1][n] = a[1][n];
    for(int i=2;i<=n;i++){
        for(int j=n-i+1;j<=n+i-1;j++){
            dp[i][j] = max(dp[i][j],dp[i-1][j]+a[i][j]);
            dp[i][j] = max(dp[i-1][j-1]+a[i][j],dp[i][j]);
            dp[i][j] = max(dp[i-1][j+1]+a[i][j],dp[i][j]);
        }
    }
    int ans = 0;
    for(int i=n-k;i<=n+k;i++){
        ans = max(ans,dp[n][i]);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
