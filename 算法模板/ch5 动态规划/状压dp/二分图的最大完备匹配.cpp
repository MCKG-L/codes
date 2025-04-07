#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
/*
给定二分图，两个集合都有 N 个点，ai,j​=1 表示第一个集合第 i 个点与第二个集合第 j 个点连边。
求二分图完备匹配数，答案对 109+7 取模
*/
void solve(){
	int n;cin >> n;
	vector<vector<int>> a(n + 1,vector<int>(n + 1,-1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin >> a[i][j];
	}
	vector<vector<int>> dp(n + 1,vector<int>(1ll<<n,0));
	for(int i=0;i<=n;i++) dp[i][0] = 1;
	for(int i=1;i<1<<n;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if((i >> j & 0x1)) cnt ++;
		}
		// cerr << cnt << endl;
		for(int j=1;j<=n;j++){
			// if(!a[cnt][j] || ((i >> j-1) & 0x1 == 0)) continue;
			// dp[cnt][i] = (dp[cnt][i] + dp[cnt-1][i - (1 << j-1)]) % mod;
			if(a[cnt][j] && (i >> j-1) & 0x1) {
				dp[cnt][i] = (dp[cnt][i] + dp[cnt-1][i-(1<<j-1)]) % mod;
			}
 		}
	}
	cout << dp[n][(1<<n)-1] << endl;
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