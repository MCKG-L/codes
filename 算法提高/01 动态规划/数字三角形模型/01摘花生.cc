#include <iostream>
using namespace std;
const int N = 110;
int a[N][N];
int dp[N][N];
int n,m;
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    //保证dp[i][j]所依赖的位置都已经被算过
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    cout << dp[n][m] << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}