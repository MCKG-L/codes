#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> b(n+1),a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin()+1,b.end());
    function<int(void)> f = [&]() -> int {
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++) dp[0][i] = 0;
        for(int i=1;i<=n;i++){
            int mn = INF;
            for(int j=1;j<=n;j++){
                mn = min(mn,dp[i-1][j]);
                dp[i][j] = mn + abs(a[i]-b[j]);
            }
        }
        int res = INF;
        for(int i=1;i<=n;i++) res = min(res,dp[n][i]);
        return res;
    };
    int ans = f();
    reverse(a.begin()+1,a.end());
    ans = min(ans,f());
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}