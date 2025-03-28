#include <iostream>
using namespace std;
const int N = 1010;
int n,m;
int v[N],w[N],dp[N][N];
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i] >> w[i];

    for(int i=n;i>=1;i--){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i+1][j];
            if(j >= v[i]) dp[i][j] = max(dp[i][j],dp[i+1][j-v[i]]+w[i]);
        }
    }
    //找出字典序最小的方案
    int sum = m;
    for(int i=1;i<=n;i++){
        if(sum >= v[i] && dp[i][sum] == dp[i+1][sum-v[i]]+w[i]){
            cout << i << ' ';
            sum -= v[i];
        }
    }
    cout << endl;
    return 0;
}