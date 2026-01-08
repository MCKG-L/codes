#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 5e3 + 10,M = 1e5 + 10;
/*百度之星2024 R2T4
给一个长度为n的01序列，可以操作k次：将某一个位置翻转
问可以得到多少种方案，使得01串不含110字串
*/
/* 0->...0 1->...01 2->...11
dp[i][j][k]
c == 1:
dp[i][j][0] = dp[i-1][j-1][0] + dp[i-1][j-1][1]
dp[i][j][1] = dp[i-1][j][0]
dp[i][j][2] = dp[i-1][j][1] + dp[i-1][j][2]
c == 0:
dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]
dp[i][j][1] = dp[i-1][j-1][0]
dp[i][j][2] = dp[i-1][j-1][1] + dp[i-1][j-1][2]
*/
void solve(){
    int n,k;
    cin >> n >> k;
    string s;cin >> s;
    s = ' ' + s;
    vector<array<int,3>> dp[2];
    dp[0].assign(k + 1,{});
    dp[1].assign(k + 1,{});
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        int now = i % 2;
        for(int j=0;j<=k;j++){
            if(s[i] == '1'){
                if(j >= 1) dp[now][j][0] = (dp[now^1][j-1][0] + dp[now^1][j-1][1]) % mod;
                dp[now][j][1] = dp[now^1][j][0];
                dp[now][j][2] = (dp[now^1][j][1] + dp[now^1][j][2]) % mod;
            }else{
                dp[now][j][0] = (dp[now^1][j][0] + dp[now^1][j][1]) % mod;
                if(j >= 1){
                    dp[now][j][1] = dp[now^1][j-1][0];
                    dp[now][j][2] = (dp[now^1][j-1][1] + dp[now^1][j-1][2]) % mod;
                }
            }
        }
        dp[now ^ 1].assign(k + 1,{});
    }
    int ans = 0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<3;j++){
            ans = (ans + dp[n % 2][i][j]) % mod;
        }
    }
    cout << ans << endl;
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
