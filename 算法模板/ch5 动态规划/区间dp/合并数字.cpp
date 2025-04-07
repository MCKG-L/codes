#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
/* 
有 n 个数，第 i 个数是 ai​ ，现在要进行 n−1 次操作。
对于每一次操作，可以把相邻两个数合并起来
并写上他们的和，这次操作的代价就是这个和。
求代价最小值。
和石子合并那题一模一样
*/
void solve(){
	int n;cin >> n;
	vector<int> a(n + 1),pre(n + 1);
	for(int i=1;i<=n;i++){
		cin >> a[i];pre[i] = pre[i-1] + a[i];
	}
	vector<vector<int>> dp(n + 1,vector<int>(n + 1,inf));
	for(int i=1;i<=n;i++) dp[i][i] = 0;
	for(int i=n;i>=1;i--){ //reverse
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+pre[j]-pre[i-1]);
			}
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