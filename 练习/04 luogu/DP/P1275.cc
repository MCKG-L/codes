#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
void solve(){
    int n,l,r;
    cin >> n >> l >> r;
    vector<int> dp(n+10,-INF),a(n+10);
    for(int i=0;i<=n;i++) cin >> a[i];
    vector<int> q(n+10);
    int hh = 0,tt = -1;
    dp[0] = 0;
    int k = r - l + 1;
    for(int i=0;i<=n-l;i++){
        if(hh <= tt && i - k + 1 > q[hh]) hh ++;
        while(hh <= tt && dp[q[tt]] <= dp[i]) tt --;
        q[++tt] = i;
        dp[i+l] = a[i+l] + dp[q[hh]];
    }
    int ans = -1e9;
    for(int i=n-r+1;i<=n;i++) ans = max(ans,dp[i]);
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