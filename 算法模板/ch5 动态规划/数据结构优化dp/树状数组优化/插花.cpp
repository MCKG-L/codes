#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e5 + 10;
int tr[N],n;
/*
有一排花，共 n 个，第 i 个的高度是 hi​ ，权值是 ai​ ，保证高度互不相同。
现在拿走一些花，使剩下的花高度单调递增，问剩下的花权值之和最大是多少。

dp[i] = Max{dp[1,h[i]-1]} + w[i]
*/
void add(int x,int t){
	for(int i=x;i<=n;i+=i&-i) tr[i] = max(tr[i],t);
}
int get(int x){
	int ans = 0;
	for(int i=x;i;i-=i&-i) ans = max(ans,tr[i]);
	return ans;
}
void solve(){
	cin >> n;
	vector<int> h(n + 1),w(n + 1);
	for(int i=1;i<=n;i++) cin >> h[i];
	for(int i=1;i<=n;i++) cin >> w[i];
	vector<int> dp(n + 1,-inf);
	dp[0] = 0;
	int ans = 0;
	for(int i=1;i<=n;i++){
		dp[i] = get(h[i]-1) + w[i];
		ans = max(ans,dp[i]);
		add(h[i],dp[i]);
	}
	cout << ans << endl;
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