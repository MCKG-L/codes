#include <iostream>
using namespace std;
/*
编辑距离：将字符串a变成字符串b所需要的最小操作次数
三种操作：将a[i]删除、添加一个字符b[i]、将a[i]变成b[i]

dp[i][j]表示 将a[1~i]变成b[1~j]的最小编辑距离
*/
/*
10
AGTCTGACGC
11
AGTAAGTAGGC
*/
const int N = 1010;
int n,m;
char a[N],b[N];
int dp[N][N];
int main()
{
    cin >> n >> a + 1;
    cin >> m >> b + 1;
    for(int i=0;i<=m;i++) dp[0][i] = i;
    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
            dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(a[i]!=b[j]));
        }
    }
    cout << dp[n][m] << endl; 
    return 0;
}