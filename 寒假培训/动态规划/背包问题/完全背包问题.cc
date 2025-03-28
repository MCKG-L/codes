#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int v[N],w[N];
int n,m;
int dp[N][N],mp[N];
int main()
{
    cin >> n >> m;//最好从1开始
    for(int i=1;i<=n;i++) cin >> w[i] >> v[i];

    //完全背包问题 朴素解法
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         for(int k=0;k*w[i] <= j;j++){
    //             dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]*k]+k*v[i]);
    //         }
    //     }
    // }

    //优化
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i][j],dp[i][j-w[i]]+v[i]);
        }
    }

    //1维优化
    for(int i=1;i<=n;i++){
        for(int j=w[i];j<=m;j++){
            mp[j] = max(mp[j],mp[j-w[i]]+v[i]);
        }
    }
    cout << dp[n][m] << endl;
    cout << mp[m];
    return 0;
}