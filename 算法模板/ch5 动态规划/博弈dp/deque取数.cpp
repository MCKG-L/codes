#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e5 + 10;
/*
给一个双端队列，双方轮流取数，每一次能且只能从队头或队尾取数，
取完数后将这个数从队列中弹出。双方都希望自己取的所有数之和尽量大，且双方都以最优策略行动，
假设先手取的所有数之和为 X，后手取的所有数之和为 Y，求 X−Y。

区间dp dp[i][j]表示剩余区间[i,j]时，取得的最大X-Y值，显然先手尽可能使其变大，后手尽可能使其变小
*/
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<vector<int>> dp(n + 1,vector<int>(n + 1,-inf));
    for(int i=1;i<=n;i++){
        if(n & 0x1) dp[i][i] = a[i];
        else dp[i][i] = -a[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j = i + len - 1;
            //second
            if((n - len) & 0x1) dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
            else dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
        }
    }
    cout << dp[1][n] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
	#ifdef LOCAL
		freopen("D:\\Others\\desktop\\text.in","r",stdin);
	#endif
    // cin >> T;
    while(T --) solve();
    return 0;
}