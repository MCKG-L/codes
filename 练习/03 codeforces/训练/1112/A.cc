#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 10010,M = 1e5 + 10;
void solve(){
    int y,n,m;
    cin >> y >> n >> m;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin >> b[i];
    vector<int> dp(y+1,1e9);
    dp[1] = 1;
    dp[0] = 0;
    vector<int> q(y+1);
    int hh = 0,tt = -1;
    int lst = 0;
    q[++tt] = 0;
    for(int i=1;i<=y;i++){
        for(int j=0;j<m;j++){
            if(i % b[j]) continue;
            dp[i] = min(dp[i],dp[i/b[j]] + 1);
        }
        dp[i] = min(dp[i],lst+1);
        if(hh <= tt && i - n + 1 > q[hh]) hh ++;
        while(hh <= tt && dp[q[tt]] >= dp[i]) tt --;
        q[++tt] = i;
        lst = dp[q[hh]];
    }
    cout << dp[y] << endl;
}
signed main()
{
    IOS;
	int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}