#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int n,k;
void solve(){
    cin >> n >> k;
    vector<vector<int>> dp(n+1,vector<int>(64,0));
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        dp[i][x] = 1;
        for(int j=0;j<64;j++){
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
            dp[i][j&x] += dp[i-1][j];
            dp[i][j&x] %= mod;
        }
    }
    ll ans = 0;
    for(int i=0;i<64;i++){
        if(__builtin_popcount(i) == k){
            ans = (ans + dp[n][i]) % mod;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}