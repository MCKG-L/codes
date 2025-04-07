#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
/*
给一棵树，每一个点可以染成黑色或白色，任意两个相邻节点不能都是黑色，求方案数，结果对 109+7 取模。

记忆化dp
*/
void solve(){
	int n;cin >> n;
	vector<vector<int>> a(n + 1);
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
    vector<array<int,2>> dp(n + 1);
    for(int i=1;i<=n;i++) dp[i][0] = dp[i][1] = -1;
	auto dfs = [&](auto &dfs,int u,int fa,int color)->void{
		if(~dp[u][color]) return;
		int t = 1;
		for(auto v : a[u]){
			if(v == fa) continue;
			int s = 0;
			dfs(dfs,v,u,color^1);
			s = (s + dp[v][color^1]) % mod;
			if(!color){
				dfs(dfs,v,u,color);
				s = (s + dp[v][color]) % mod;
			}
			t = t * s % mod;
		}
        dp[u][color] = t;
	};
	int ans = 0;
	dfs(dfs,1,0,0);
    ans = (ans + dp[1][0]) % mod;
    dfs(dfs,1,0,1);
    ans = (ans + dp[1][1]) % mod;
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