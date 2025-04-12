#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;
void solve(){
	int ans = 0;
	vector<int> a(3000),b(3000);
	vector<bool> st(3000);
	
	int n = 2025;
	
	for(int i=1;i<=n;i++) b[i] = sqrt(i * i + 2025);
	function<void(int)> dfs = [&](int u)->void{
		
		if(u > n){
			ans = (ans + 1) % mod;
			return;
		} 
		for(int i=1;i<=b[u];i++){
			bool ok = 1;
			if(st[i]) continue;
			for(int j=1;j<u;j++){
				if(j * u + 2025 < a[j] * i){
					ok = 0;
					return;
					break;
				}
			}
			if(ok){
				a[u] = i;
				st[i] = 1;
				dfs(u+1);
				st[i] = 0;
			}else{
				break;
			} 
		}
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
	//cin >> T;
	cout << (int)sqrt(233*233 + 666*666) << endl;
	while(T --) solve();
	return 0;
}
