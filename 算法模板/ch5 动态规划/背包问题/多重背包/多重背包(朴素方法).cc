#include <iostream>
using namespace std;
const int N = 2010;
int n,m;
int v[N],w[N],s[N];
int dp[N][N];
int main()
{
    //时间复杂度太高O(N^3)，不用该方法！！！
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> v[i] >> w[i] >> s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=s[i]&&k*v[i]<=j;k++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-v[i]*k]+w[i]*k);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}