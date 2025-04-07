#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18,N = 1010;
/* 环形石子合并
在一个圆形操场的四周摆放 N 堆石子，现要将石子有次序地合并成一堆，
规定每次只能选相邻的 2 堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。
试设计出一个算法,计算出将 N 堆石子合并成 1 堆的最小得分和最大得分。
*/
void solve(){
	int n;cin >> n;
	vector<int> a(n << 1 | 1),pre(n << 1 | 1);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i+n] = a[i];
	}
	for(int i=1;i<=n<<1;i++) pre[i] = pre[i-1] + a[i];
	vector<vector<int>> dp1(n << 1 | 1,vector<int>(n << 1 | 1,-inf)),dp2(n << 1 | 1,vector<int>(n << 1 | 1,inf));
	for(int i=1;i<=n<<1;i++) dp1[i][i] = dp2[i][i] = 0;
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n<<1;i++){
			int j = i + len - 1;
			for(int k=i;k<j;k++){
				dp1[i][j] = max(dp1[i][j],dp1[i][k] + dp1[k+1][j] + pre[j] - pre[i-1]);
				dp2[i][j] = min(dp2[i][j],dp2[i][k] + dp2[k+1][j] + pre[j] - pre[i-1]);
			}
		}
	}
	int ans1 = inf,ans2 = -inf;
	for(int i=1;i<=n;i++){
		ans1 = min(ans1,dp2[i][i+n-1]);
		ans2 = max(ans2,dp1[i][i+n-1]);
	}
	cout << ans1 << '\n' << ans2 << endl;
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