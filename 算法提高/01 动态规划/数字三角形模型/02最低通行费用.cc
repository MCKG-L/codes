#include <iostream>
using namespace std;
const int N = 110,INF = 1e9;
int dp[N][N];
int a[N][N];
int n;
int main()
{
    cin >> n;
    for(int i=0;i<=n;i++) dp[0][i] = dp[i][0] = INF;
    dp[1][1] = a[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}