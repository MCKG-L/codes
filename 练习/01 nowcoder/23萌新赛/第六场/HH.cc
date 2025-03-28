#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 1e4+10,M = 1010;
int dp[M][N];
int a[M][N];
int n,m,k;
int dfs(int u,int h){
    if(dp[u][h] != -1) return dp[u][h];
    if(h == m) return 0;
    int ans = 0;
    if(h+1<=m) ans += dfs(u,h+1);
    if(h+k<=m){
        int s = 0;
        for(int i=1;i<=n;i++){
            if(i == u) continue;
            s = max(s,dfs(i,h+k)+a[u][h]);
        }
        ans += s;
    }
    dp[u][h] = ans;
    return ans;
}
void solve(){
    cin >> m >> n >> k;
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> a[j][i];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,dfs(i,1));
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
