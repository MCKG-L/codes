#include <iostream>
using namespace std;
const int N = 110,M = 10010;
int dp[N][M];
int n,m;
int main()
{
    cin >> n >> m;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        int v;cin >> v;
        for(int j=m;j>=v;j--){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-v];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}