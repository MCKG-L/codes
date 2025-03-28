#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
/*
树形DP
*/
void solve(){
    int n;cin >> n;
    vector<vector<int>> a(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ans = -1;
    int inf = 1e9;
    vector<vector<int>> dp(n+1,vector<int>(10,-inf));
    function<void(int,int)> dfs = [&](int u,int f)->void{
        dp[u][0] = 1;
        for(auto v : a[u]){
            if(v == f) continue;
            dfs(v,u);
            for(int i=4;i>=1;i--){
                dp[u][i] = max(dp[u][i],dp[u][i-1]+max(dp[v][0],dp[v][3]));
            }
            if(dp[u][1] >= 5) ans = max(ans,dp[u][1]); 
            ans = max(ans,dp[u][4]);
        }
    };
    dfs(1,0);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}