#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1020;
int dp[N][N];
int a[N];
int n,m;
void solve(){
    cin >> m >> n;
    m += 6;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++) cin >> a[i],dp[i][6] = 0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            dp[i][j] = min(dp[i][j],dp[i-1][j]);
            int d = j + a[i];
            if(d > m) d = m - (d - m);
            dp[i][d] = min(dp[i][d],dp[i-1][j] + 1);
        }
    }
    if(dp[n][m] == 0x3f3f3f3f){
        cout << -1 << endl;
    }else{
        cout << dp[n][m] << endl;
    }
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}