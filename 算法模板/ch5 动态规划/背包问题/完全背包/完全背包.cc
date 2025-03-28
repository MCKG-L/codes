#include <iostream>
using namespace std;
/*
每件物品可以使用无限次，在容量一定的情况下，装出价值和最多的物品
*/
const int N = 1010;
int f[N][N];
int dp[N];
int v[N],w[N];
int n,m;
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i] >> w[i];

    //朴素做法
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k*v[i]<=j;k++){
                f[i][j] = max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    /*
    优化：数学推导
    f[i,j]=max(f[i-1][j],f[i-1][j-v]+w,f[i-1][j-2v]+2w,f[i-1][j-3v]+3w,...)
    f[i,j-v] = max(      f[i-1][j-v]  ,f[i-1][j-2v]+w, f[i-1][j-3v]+2w,...)
    则 f[i][j] = max(f[i-1][j],f[i][j-v]+w)
    */

    //优化1
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j] = f[i-1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
            //该状态 转移方程和01背包的状态转移方程极为相似
        } 
    }

    //优化为一维
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m;j++){
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
            //状态转移方程和01背包的相同 枚举顺序不同
            //完全背包这里使用的是当前层的数据，即在该层之前算过的，所以直接j从小到大枚举
        }
    }
    // cout << f[n][m] << endl;
    cout << dp[m] << endl;
    return 0;
}