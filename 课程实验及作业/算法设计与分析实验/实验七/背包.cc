#include <iostream>
using namespace std;
const int N = 1010;
int dp[N][N];
int path[N][N];
int w[N],v[N];
int n,m;
void getPath(int n,int m){
    if(path[n][m] == 0) return;
    int x = path[n][m];
    getPath(x-1,m-v[x]);
    cout << "x" << x << ' ';
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            path[i][j] = path[i-1][j];
            if(j >= v[i]){
                if(dp[i][j] < dp[i-1][j-v[i]] + w[i]){
                    dp[i][j] = dp[i-1][j-v[i]] + w[i];
                    path[i][j] = i;
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    getPath(n,m);
}
int main()
{
    int T = 1;
    // cin >> T;

    while(T --) solve();
    return 0;
}