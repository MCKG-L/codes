#include <iostream>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int dp[N];
int dfs(int n){
    if(dp[n] != -1) return dp[n];
    int ans = 0;
    for(int i=1;i<=n/i;i++){
        if(n % i == 0){
            if(i * i == n) ans ++;
            else ans += 2;
        }
    }
    dp[n] = ans;
    return ans;
}
signed main()
{
    int n;cin >> n;
    for(int i=0;i<=n;i++) dp[i] = -1;
    dp[1] = 1;dp[2] = 2;
    if(n == 1){
        cout << 0 << endl;
    }else{
        int ans = 0;
        for(int i=1;i<n;i++) ans += dfs(i)*dfs(n-i);
        cout << ans << endl;
    }
    return 0;
}