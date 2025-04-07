#include <iostream>
#define int long long
using namespace std;
/*
合并石子 有N堆石子，编号分别为1~N，每一次只能合并相邻的两堆，合并的代价是两堆石子的重量之和。
求将所有石子合并成一堆，所用的代价最小是多少？
*/
/*
f[i][j]表示将编号为i~j的石子合并所需的最小代价  f[1][n];
状态转移：f[i][j] = Max{f[i][k]+f[k+1][j]+s[j]-s[i-1]} k = i,i+1,...,j-1
*/
//区间dp
const int N = 410,INF = 1e9;
int dp[N][N],s[N];
int n;
signed main()
{
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        s[i] += s[i-1];
    }
    
    for(int len = 2;len <= n;len ++){//区间长度
        for(int i=1;i+len-1<=n;i++){//起点
            int l = i,r = i + len - 1;
            dp[l][r] = INF;
            for(int k=l;k<r;k++){//决策
                dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}