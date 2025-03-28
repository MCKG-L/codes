#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 502;
int g[N][N];
int dp[2][N][1005];
void solve(){
    int n,m,x;
    cin >> n >> m >> x;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=x;j++) dp[0][i][j] = dp[1][i][j] = 0;
    }
    for(int i=1;i<=n;i++){
        string s;cin >> s;
        s = " " + s;
        for(int j=1;j<=m;j++){
            if(s[j] == '1') g[i][j] = 1;
            if(s[j] == '0') g[i][j] = 0;
            if(s[j] == '?') g[i][j] = -1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=x;k++){
                if(g[i][j] == -1 && k + 1 <= x){
                    dp[i & 1][j][k+1] = max(dp[i-1&1][j][k],dp[i&1][j-1][k]) + 1;
                }else{
                    dp[i&1][j][k] = max(dp[i&1][j][k],max(dp[i-1&1][j][k],dp[i&1][j-1][k])+(g[i][j] == 1));
                    // dp[i & 1][j][k] = max({dp[i&1][j][k],dp[i-1&1][j][k]+(g[i][j] == 1),dp[i&1][j-1][k] + (g[i][j] == 1)});
                }
            }
        }
    }
    int ans = -1;
    for(int i=0;i<=x;i++) ans = max(ans,dp[n & 1][m][i]);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}