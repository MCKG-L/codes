#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
/*
K 颗糖分给 n 个人，第 i 个人至少分得 0 颗，至多分得 ai​ 颗，
必须分完，求方案数，答案对 109+7 取模。
dp[i][j] = sum(dp[i-1][max(0,j-a[i]),j])
*/
void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<i128> dp(m + 1);
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[0] = 1;
	vector<i128> pre(m + 10);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+1;j++){
			pre[j] = pre[j-1] + dp[j-1];
			pre[j] %= mod;
		}
		for(int j=0;j<=m;j++){
			//注意取模 防止出现负值
			dp[j] = (pre[j+1] - pre[max(0ll,j-a[i])] % mod + mod) % mod;
			dp[j] %= mod;
		}
	}
	cout << (int)dp[m] << endl;
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