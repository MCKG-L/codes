#include <bits/stdc++.h>
using namespace std;
/*
降维 矩阵压缩 动态规划
在列的方向上求前缀和
*/
const int N = 125;
int a[N][N];
void solve(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            a[i][j] += a[i-1][j];//列前缀和
        }
    }
    //遍历
    int dp[N]={};
    int ans = -1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=n;k++){
                int f = a[i][k] - a[i-j][k];//找到压缩后列上的值
                dp[k] = max(dp[k-1]+f,f);//动态规划
                ans = max(ans,dp[k]);//更新答案
            }
        }
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}