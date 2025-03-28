#include <iostream>
#include <algorithm>
using namespace std;
const int N = 25000;
int w[N],v[N],dp[N][1010];
int n,m;
int f[N];
int main()
{
    cin >> n >> m;
    int cnt = 0;
    //打包
    for(int i=1;i<=n;i++){
        int a,b,s;
        cin >> a >> b >> s;
        int k=1;
        while(k <= s){
            cnt++;
            w[cnt] = a * k;
            v[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0){
            cnt ++;
            w[cnt] = a * s;
            v[cnt] = b * s;
        }
    }
    n = cnt;
    // //01背包
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         dp[i][j] = dp[i-1][j];
    //         if(j >= w[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
    //     }
    // }
    // return dp[n][m];
    //一维01背包
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j] = max(f[j],f[j-w[i]]+v[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}