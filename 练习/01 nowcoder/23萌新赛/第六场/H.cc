#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 1e4 + 10,M = 1010;
int a[N][M];
int dp[N][M];
int p[N];
int n,m,k;
void solve(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        dp[1][i] = a[1][i];
        p[1] = max(p[1],a[1][i]);
    }
    int ans = p[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(i - k > 0){
                dp[i][j] = max(dp[i][j],p[i-k]+a[i][j]);
            }
            p[i] = max(p[i],dp[i][j]);
        }
        ans = max(ans,p[i]);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
