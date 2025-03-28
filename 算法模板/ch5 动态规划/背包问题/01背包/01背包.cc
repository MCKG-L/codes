#include <iostream>
using namespace std;
/*
每个物品最多使用一次，在背包容量有限的情况下，装出价值总和最多的物品
*/
/*
典例：
有N件物品和一个容量是V的背包，每件物品只能使用一次。
第i件物品的体积是vi，价值是wi
问 将哪些物品装入背包可以使这些去拼的总体积不超过背包容量，且总价值最大
求出最大价值
*/
/*
4 5
1 2
2 4
3 4
4 5
*/
const int N = 1010;
int n,m;
int v[N],w[N];
int dp[N][N];
int dq[2][N];//使用滚动数组优化
int f[N];//保留的是第二维，注意范围
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
    //朴素版本
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-v[i]] + w[i]);
        }
    }

    //改滚动数组通法
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dq[i & 1][j] = dq[i-1&1][j];
            if(j >= w[i]) dq[i & 1][j] = max(dq[i&1][j],dq[i-1&1][j-v[i]] + w[i]);
        }
    }

    cout << dq[n & 1][m] << endl;
    
    //优化为一维 滚动数组
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            //如果j从小到大枚举，j-v[i]严格小于j，所以在计算f[j]是用到的f[j-v[i]]在这一层计算过了
            //即用到的是dp[i][j-v[i]]

            //如果j从大到小枚举，在计算f[j]时，显然f[j-v[i]]还未计算过，则其储存的是上一层计算的结果，即dp[i-1][j-v[i]]
            f[j] = max(f[j],f[j-v[i]] + w[i]);
        }
    }
    cout << dp[n][m] << endl;
    // cout << f[m] << endl;
    return 0;
}