#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e5 + 10;
/*
现
有N(1≤N≤300)个盘子，编号为1,2,3,…,N。第i个盘子中放有ai​(1≤ai​≤3)个寿司。
接下来每次执行以下操作，直至吃完所有的寿司。从第1,2,3,…,N个盘子中任选一个盘子，吃掉其中的一个寿司。若没有寿司则不吃。
若将所有寿司吃完，请问此时操作次数的数学期望是多少？
*/
void solve(){
	int n;cin >> n;
	vector<vector<vector<long double>>> dp(n + 2,vector<vector<long double>>(n + 2,vector<long double>(n + 2,0.0)));
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;
	for(int i=1;i<=n;i++){
		int x;cin >> x;
		if(x == 1) cnt1 += 1;
		if(x == 2) cnt2 += 1;
		if(x == 3) cnt3 += 1;
	}
	cerr << cnt1 << ' ' << cnt2 << ' ' << cnt3 << endl;
	for(int k=0;k<=n;k++){
		for(int j=0;j<=n;j++){
			for(int i=0;i<=n;i++){
				if(i || j || k){
					if(i) dp[i][j][k] += dp[i-1][j][k] * i;
					if(j) dp[i][j][k] += dp[i+1][j-1][k] * j;
					if(k) dp[i][j][k] += dp[i][j+1][k-1] * k;
					dp[i][j][k] = (dp[i][j][k] + n) / (i + j + k);
				}
			}
		}
	}
	cout  << fixed << setprecision(15) << dp[cnt1][cnt2][cnt3] << endl;
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