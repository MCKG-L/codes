#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int inf = 1e9,mod = 1e9 + 7;
void solve(){
	int n;cin >> n;
	vector<int> a(n + 1);
	for(int i=1;i<=n;i++) cin >> a[i];
	int ans = 0;
	vector<char> s(n + 1);
	map<char,int> mp;
	mp['+'] = mp['-'] = 1;
	mp['^'] = 2;
	int cnt = 0;
	function<void(int)> dfs = [&](int u)->void{
		if(u >= n){
			cnt ++;
			stack<int> num;
			stack<char> op;
			for(int i=1;i<=n;i++){
				num.push(a[i]);
				while(op.size() && mp[op.top()] >= mp[s[i]]){
					int r2 = num.top();num.pop();
					int r1 = num.top();num.pop();
					char opp = op.top();op.pop();
					int x ;
					if(opp == '+') x = r1 + r2;
					if(opp == '-') x = r1 - r2;
					if(opp == '^') x = r1 ^ r2;
					num.push(x); 
				}
				if(i < n) op.push(s[i]);
			}
			while(op.size()){
				int r2 = num.top();num.pop();
					int r1 = num.top();num.pop();
					char opp = op.top();op.pop();
					int x ;
					if(opp == '+') x = r1 + r2;
					if(opp == '-') x = r1 - r2;
					if(opp == '^') x = r1 ^ r2;
					num.push(x); 
			}
			ans = (ans + num.top()) % mod;
			return;
		}
		s[u] = '+';
		dfs(u+1);
		s[u] = '-';
		dfs(u+1);
		s[u] = '^';
		dfs(u+1);
	};
	dfs(1);
	cout << ans << endl; 
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
