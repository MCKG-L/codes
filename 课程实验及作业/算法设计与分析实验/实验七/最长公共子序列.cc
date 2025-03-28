#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int dp[N][N];//范围dp 1..i 1...j的LCS
void solve(){
    string a,b;
    cin >> a >> b;
    int n = a.size(),m = b.size();
    a = ' ' + a,b = ' ' + b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
        }
    }
    cout << dp[n][m] << endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << dp[i][j] << " \n"[j==m];
    //     }
    // }
}
int main()
{
    int T = 1;
    // cin >> T;

    while(T --) solve();
    return 0;
}