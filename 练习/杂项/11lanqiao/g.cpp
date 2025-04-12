#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int inf = 1e9;
void solve(){
	int n;
	cin >> n;
	vector<int> w(n + 1);
	for(int i=1;i<=n;i++) cin >> w[i];
	vector<vector<int>> a(n+1);
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	} 
	vector<vector<int>> cost(n + 1);
	int m = 1000;
	vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
	vector<int> dpp(m + 1);
	function<void(int,int)> dfs = [&](int u,int fa)->void{
		vector<int> alls;
		for(auto v : a[u]){
			if(v == fa) continue;
			dfs(v,u);
			for(auto x : cost[v]){
				alls.push_back(x);
			}
		}
		if(alls.size() == 0) alls.push_back(w[u]);
		dpp[0] = 1;
		for(int i=1;i<=m;i++) dpp[i] = 0;
		for(int i=0;i<alls.size();i++){
			for(int j=w[u];j>=alls[i];j--){
				dp[u][j] = max(dp[u][j],dp[u][j-alls[i]]+alls[i]);
				dpp[j] |= dpp[j-alls[i]];
			}
		}
		for(int i=1;i<=w[u];i++){
			if(dpp[i]) cost[u].push_back(i);
		}
	};
	dfs(1,0);
	cout << dp[1][w[1]] << endl;
} 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	#ifdef LOCAL
		freopen("C:\\Users\\lanqiao\\text.in","r",stdin);
	#endif
	int T = 1;
//	cin >> T;
	while(T --) solve();
	return 0;
}
