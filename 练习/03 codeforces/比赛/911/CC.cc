#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10,INF = 2e9;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = ' ' + s;
    vector<int> l(n+1),r(n+1);
    for(int i=1;i<=n;i++){
        int a,b;cin >> a >> b;
        l[i] = a,r[i] = b;
    }
    vector<int> dp(n+1,INF);
    function<void(int)> dfs = [&](int u) -> void {
        if(l[u] == 0 && r[u] == 0){
            dp[u] = 0;return;
        }
        if(l[u]){
            dfs(l[u]);
            if(s[u] == 'L') dp[u] = min(dp[u],dp[l[u]]);
            else dp[u] = min(dp[l[u]]+1,dp[u]);
        }
        if(r[u]){
            dfs(r[u]);
            if(s[u] == 'R') dp[u] = min(dp[u],dp[r[u]]);
            else dp[u] = min(dp[u],dp[r[u]]+1);
        }
    };
    dfs(1);
    cout << dp[1] << endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}