#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 5e5 + 10,mod = 1e9 + 7,inf = 1e18;
/* abc_403_f
用一个只包含 +、*、1、( 和 ) 的表达式表示出 N，求最短的满足条件的表达式。
403: 1+(1+1+1)*(1+11+11+111)
11 : 11
9  : (1+1+1)*(1+1+1)
*/
void solve(){
    int n;cin >> n;
    vector<array<int,2>> dp(2010,{inf,inf});//1 -> *
    vector<array<string,2>> path(2010);
    dp[1][1] = 1,dp[11][1] = 2,dp[111][1] = 3,dp[1111][1] = 4;
    path[1][1] = "1",path[11][1] = "11",path[111][1] = "111",path[1111][1] = "1111";
    for(int i=2;i<=n;i++){
        if(i == 11 || i == 111 || i == 1111) continue;
        //+
        for(int j=1;j<i;j++){
            int a = j,b = i - j;
            int t = min(dp[a][0],dp[a][1]) + min(dp[b][0],dp[b][1]) + 1;
            if(dp[i][0] <= t) continue;
            dp[i][0] = t;
            path[i][0] = (dp[a][0] < dp[a][1] ? path[a][0] : path[a][1]) + "+" +
             (dp[b][0] < dp[b][1] ? path[b][0] : path[b][1]);
        }
        for(int j=2;j<=i/j;j++){
            if(i % j) continue;
            int a = j,b = i / j;
            int t = min(dp[a][0]+2,dp[a][1]) + min(dp[b][0]+2,dp[b][1]) + 1;
            if(dp[i][1] <= t) continue;
            dp[i][1] = t;
            path[i][1] = (dp[a][0]+2 < dp[a][1] ? "("  + path[a][0] + ")" : path[a][1]) + "*" + 
            (dp[b][0]+2 < dp[b][1] ? "(" + path[b][0] + ")" : path[b][1]);
        }
    }
    cout << (dp[n][0] < dp[n][1] ? path[n][0] : path[n][1]) << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}