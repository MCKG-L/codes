#include <iostream>
using namespace std;
const int N = 1010,INF = 1e9;
int a[N][N],dp[N][N];
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

10
-6
-4 -5
-3 7 5
3 7 -2 1
10 2 -6 2 -6
-8 3 8 6 7 9
-4 -10 0 -3 4 9 2
0 5 5 5 10 -6 -5 -4
-9 7 4 9 8 -5 -2 3 2
-7 -4 0 -10 -8 -4 3 -5 8 9
*/
int main()
{
    int n;cin >> n;
    //初始化
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i+1;j++){
            dp[i][j] = -INF;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
        }
    }
    int max_n = 0;
    for(int i=1;i<=n;i++){
        max_n = max(max_n,dp[n][i]);
    }
    cout << max_n << endl;
    return 0;
}