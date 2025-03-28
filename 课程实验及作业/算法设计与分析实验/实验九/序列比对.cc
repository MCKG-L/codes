#include <iostream>
#define endl '\n'
using namespace std;
const int N = 1100;
int dp[N][N];
void solve(){
    string a,b;
    cin >> a >> b;
    int n = a.size(),m = b.size();
    a = ' ' + a,b = ' ' + b;
    for(int i=1;i<=n;i++) dp[i][0] = -2 * i;
    for(int i=1;i<=m;i++) dp[0][i] = -2 * i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max(0,dp[i-1][j-1] + (a[i] == b[j] ? 2 : -2));
            dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1])-1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << dp[i][j] << " \n"[j == m];
        }
    }
    cout << dp[n][m] << endl;
}
int main()
{
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}