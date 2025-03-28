#include <bits/stdc++.h>
using namespace std;
const int N = 55,mod = 1e9 + 7;
using ll = long long;
int a[N][N];
int dp[N][N][15][15];//在位置(i,j)时，手中物品数目为cnt，最大价值为v的总方案数
int n,m,k;
void solve(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            a[i][j] ++;//区分物品为空的情况和总价值为0的情况
        }
    }
    dp[1][1][0][0] = 1;
    dp[1][1][1][a[1][1]] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i == 1 && j == 1) continue;
            for(int cnt=0;cnt<=k;cnt++){
                for(int w=0;w<=13;w++){

                    //不拿走
                    dp[i][j][cnt][w] = (dp[i][j][cnt][w] + dp[i-1][j][cnt][w]) % mod;
                    dp[i][j][cnt][w] = (dp[i][j][cnt][w] + dp[i][j-1][cnt][w]) % mod;

                    //拿走
                    if(w == a[i][j] && cnt > 0){
                        for(int v=0;v<a[i][j];v++){
                            dp[i][j][cnt][w] = (dp[i][j][cnt][w] + dp[i-1][j][cnt-1][v]) % mod;
                            dp[i][j][cnt][w] = (dp[i][j][cnt][w] + dp[i][j-1][cnt-1][v]) % mod;
                        }
                    }
                }
            }
        }
    }
    ll res = 0;
    for(int i=1;i<=13;i++) res = (res + dp[n][m][k][i]) % mod;
    cout << res << endl;
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