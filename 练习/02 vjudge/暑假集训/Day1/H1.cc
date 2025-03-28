#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10,mod = 1e9 + 7;;
// int dp[N][64];
int n,k;
void solve(){
    cin >> n >> k;
    // memset(dp,0,sizeof dp);
    vector<vector<int>> dp(n+1,vector<int>(64,0));
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        dp[i][x] ++;
        for(int j=0;j<64;j++){
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
            dp[i][j&x] += dp[i-1][j];
            dp[i][j&x] %= mod;
        }
    }
    int ans = 0;
    for(int i=0;i<64;i++){
        if(__builtin_popcount(i) == k){
            ans = (ans + dp[n][i]) % mod;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}