#include <iostream>
using namespace std;
const int N = 15;
int dp[N*2][N][N];
int w[N][N];
int n;
/*
dp[i1][j1][i2][j2] 表示在某一时刻，两条路径，其中第一条路径从(1,1)走到(i1,j1)
第二条路径从(1,1)走到(i2,j2)取数的最大值
注意定义状态时，要求时同一时刻，所以当i1 + j1 != i2 + j2时，表示两条路径不是同一时刻，直接跳过
所以可以优化位三维 dp[k][i1][i2] k即i1 + j1
对于状态计算，考虑最后一步，根据两条路径的选择，有4中情况，取最值即可
注意：如果最后一步，两条路径从同一个格子出发，则根据题意，只能加一次数，如果不是同一个格子，正常加
*/
int main()
{
    cin >> n;
    int a,b,c;
    while(cin >> a >> b >> c){
        if(a == 0 && b == 0 && c == 0) break;
        w[a][b] = c;
    }
    for(int k=2;k<=n*2;k++){
        for(int i1=1;i1<=n;i1++){
            for(int i2=1;i2<=n;i2++){
                int j1 = k-i1,j2 = k-i2;
                if(j1 < 0 || j1 > n || j2 < 0 || j2 > n) continue;
                int t = w[i1][j1];
                if(i1 != i2) t += w[i2][j2];
                int & x = dp[k][i1][i2];
                x = max(x,dp[k-1][i1-1][i2-1] + t);
                x = max(x,dp[k-1][i1-1][i2]+t);
                x = max(x,dp[k-1][i1][i2-1]+t);
                x = max(x,dp[k-1][i1][i2]+t); 
            }
        }
    }
    cout << dp[n*2][n][n] << endl;
    return 0;
}