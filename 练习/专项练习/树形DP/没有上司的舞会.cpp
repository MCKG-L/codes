#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int inf = 1e9;
void solve(){
    int n;cin >> n;
    vector<int> p(n + 1);
    vector<vector<int>> a(n+1);
    vector<bool> st(n + 1);
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v; //v是u的上司
        st[u] = 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<vector<int>> dp(n+1,vector<int>(2,-inf));
    int ans = 0;
    function<void(int,int)> dfs = [&](int u,int f)->void{
        dp[u][1] = p[u];dp[u][0] = 0;
        for(auto v : a[u]){
            if(v == f) continue;
            dfs(v,u);
            dp[u][0] += max(dp[v][0],dp[v][1]);
            dp[u][1] += dp[v][0];
        }
        // ans = max(ans,max(dp[u][0],dp[u][1]));
    };
    int root = -1;
    for(int i=1;i<=n;i++){
        if(!st[i]){
            root = i;break;
        }
    }
    dfs(root,0);
    cout << max(dp[root][0],dp[root][1]) << endl;
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