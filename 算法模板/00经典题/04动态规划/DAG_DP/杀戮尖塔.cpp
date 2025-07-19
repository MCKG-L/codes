#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
/* DAG+DP
dp[u][j]使用j次魔法到达节点u时的最大战力
不使用魔法k->u:dp[k][j] >= a[u]时：dp[u][j] = dp[k][j] + b[u]
使用魔法k->u:dp[u][j] >= a[k]且d[u]==d[k]+1:dp[u][j] = Max{dp[k][j-1]} + b[u]
维护d[k]时的最大值，Mx[d[k]][j]
dp[u][j] = Max(dp[u][j],Mx[d[u]-1][j-1]+b[u])
*/
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> a(n + 1),b(n + 1);
	vector<vector<int>> g(n + 1);
	for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
	for(int i=1;i<=m;i++){
		int u,v;cin >> u >> v;
		g[u].push_back(v);
	}
	if(k < a[1]){
		cout << "NO" << endl;
		return;
	}
	queue<int> q;
	vector<array<int,4>> dp(n+1,{-inf,-inf,-inf,-inf}),Mx(n+1,{-inf,-inf,-inf,-inf});
	vector<int> d(n + 1);
	d[1] = 1;
	dp[1][0] = b[1] + k;Mx[1][0] = b[1] + k;
	q.push(1);
	vector<bool> st(n + 1);
	st[1] = 1;
	while(q.size()){
		auto u = q.front();q.pop();
		for(int i=1;i<4;i++){
			if(Mx[d[u]-1][i-1] >= a[u]){
				dp[u][i] = max(dp[u][i],Mx[d[u]-1][i-1]+b[u]);
				Mx[d[u]][i] = max(Mx[d[u]][i],dp[u][i]);
			}
		}
		for(auto v : g[u]){
			d[v] = d[u] + 1;
			if(!st[v]) q.push(v),st[v] = 1;
			for(int i=0;i<4;i++){
				if(dp[u][i] >= a[v]){
					dp[v][i] = max(dp[v][i],dp[u][i] + b[v]);
					Mx[d[v]][i] = max(Mx[d[v]][i],dp[v][i]);
				}
			}
		}
	}
	int Max = -inf;
	for(int i=0;i<4;i++) Max = max(Max,dp[n][i]);
	cout << (Max > -inf/2 ? "YES" : "NO") << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}