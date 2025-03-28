#include <iostream>
#include <vector>
using namespace std;
const int N = 10010;
int dp[N][N];//前i个物品 体积为m 所得最大价值
int w[N],v[N];
int n,m;
int f[N];
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m;j++){
            //第i个物品不选
            dp[i][j] = dp[i-1][j];

            //选择第i个物品
            dp[i][j] = min(dp[i][j],dp[i-1][j-v[i]] + w[i]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            f[j] = min(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout << f[m] << endl;
    // cout << dp[n][m] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) solve();
    return 0;
}