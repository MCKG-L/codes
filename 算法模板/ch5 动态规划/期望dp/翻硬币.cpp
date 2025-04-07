#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e5 + 10;
/*
设 N 是一个正的奇数。
有 N 枚硬币，每枚硬币上标有编号 1,2,…,N。对于每个 i (1≤i≤N)，掷硬币 i 时，正面朝上的概率是 pi​，反面朝上的概率是 1−pi​。
太郎君把这 N 枚硬币全部投掷了一次。请计算正面朝上的硬币数多于反面朝上的硬币数的概率。
*/
void solve(){
	int n;cin >> n;
	vector<long double> a(n + 1);
	for(int i=1;i<=n;i++) cin >> a[i];
	vector<vector<long double>> dp(n + 1,vector<long double>(n + 1,0.0));
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		dp[i][0] = dp[i-1][0] * (1 - a[i]);
		for(int j=1;j<=i;j++){
			dp[i][j] = dp[i-1][j-1] * a[i] + dp[i-1][j] * (1 - a[i]);
		}
	}
	long double ans = 0;
	for(int i=(n + 1) / 2;i<=n;i++) ans += dp[n][i];
	cout << fixed << setprecision(10) << ans << endl;
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