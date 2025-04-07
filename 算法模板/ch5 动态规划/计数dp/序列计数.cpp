#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
/*
有一个长为 N 的正整数排列。给定一个由 < 和 > 组成长为 N−1 的的字符串。 
对于任意满足 1≤i≤N−1 的字符 si​，如果 si​ 是 < 则 Pi​<Pi+1​、如果 si​ 是 > 则 Pi​>Pi+1​。
求满足这样的性质的排列 P 的方案数。
*/
void solve(){
	int n;cin >> n;
	string s;cin >> s;
	s = ' ' + s;
	vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
	//dp[i][j]表示前i个位置中，第i个位置选择的数是第j小的方案数
	//s[i-1] < s[i]时：dp[i][j] = sum(dp[i-1][1~j-1])
	//s[i-1] > s[i]时：dp[i][j] = sum(dp[i-1][j~i]) 因为前i-1中的第j小将变成第j+1小 所以可以取到第j小
	vector<int>pre(n + 1,0);
	dp[1][1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++) pre[j] = (pre[j-1] + dp[i-1][j]) % mod;
		for(int j=1;j<=i;j++){
			if(s[i-1] == '<'){ //dp[i][j] = sum(dp[i-1][1~j-1])
				dp[i][j] = pre[j-1];
			}else{ //dp[i][j] = sum(dp[i-1][j,i])
				dp[i][j] = (pre[i] - pre[j-1] + mod) % mod;
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++) ans = (ans + dp[n][i]) % mod;
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