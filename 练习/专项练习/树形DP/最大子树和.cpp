#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int inf = 2147483647;
void solve(){
    int n;cin >> n;
    vector<int> p(n + 1);
    for(int i=1;i<=n;i++) cin >> p[i];
    vector<vector<int>> a(n+1);
    vector<int> dp(n+1,-inf);
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    function<void(int,int)> dfs = [&](int u,int fa)->void{
        dp[u] = p[u];
        for(auto v : a[u]){
            if(v == fa) continue;
            dfs(v,u);
            dp[u] = max(dp[u],dp[u]+dp[v]);
        }
    };
    dfs(1,0);
    int ans = -inf;
    for(int i=1;i<=n;i++) ans = max(ans,dp[i]);
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