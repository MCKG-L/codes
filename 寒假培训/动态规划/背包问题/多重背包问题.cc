#include <iostream>
#include <algorithm>
using namespace std;
/*
多重背包问题
第i个物品最多选择s[i]次
*/
const int N = 1010;
int w[N],v[N],s[N],n,m;
int dp[N][N];
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i] >> s[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=s[i]&&j>=w[i]*k;k++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]*k]+v[i]*k);
            }
        }
    }

    //二进制优化
    
    cout << dp[n][m] << endl;
}