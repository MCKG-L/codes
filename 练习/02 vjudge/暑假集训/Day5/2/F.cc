#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,r;
void solve(){
    cin >> n >> m >> r;
    vector<vector<vector<bool>>> book(n+1,vector<vector<bool>>(m+1,vector<bool>(r+1,1)));
    vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>>(m+1,vector<bool>(r+1,0)));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=r;k++) book[i][j][k] = 1;
        }
    }
    for(int j=0;j<r;j++){
        int t,d,x;
        cin >> t >> d >> x;
        if(d == 1){
            for(int i=0;i<=m;i++){
                int k = t - x - i;
                if(k >= 0 && k <= r){
                    book[x][i][k] = 0;
                }
            }
        }else{
            for(int i=0;i<=n;i++){
                int k = t - i - x;
                if(k >= 0 && k <= r){
                    book[i][x][k] = 0;
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=r;k++){
                // dp[i][j][k] = 0;
                // if(i == 0 && j == 0 && k == 0) dp[i][j][k] = 1;
                dp[i][j][k] = !(i || j || k);
                if(book[i][j][k]){ //在i+j+k时刻可以到达(i,j)
                    if(i != 0 && dp[i-1][j][k]) dp[i][j][k] = 1;
                    if(j != 0 && dp[i][j-1][k]) dp[i][j][k] = 1;
                    if(k != 0 && dp[i][j][k-1]) dp[i][j][k] = 1;
                }
            }
        }
    }
    int ans = -1;
    for(int i=0;i<=r;i++){
        if(dp[n][m][i]){
            ans = n + m + i;
            break;
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}