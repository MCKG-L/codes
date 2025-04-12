#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
void solve(){
	int n;cin >> n;
	int ans = 0;
	for(int i=0;i<n;i++){
		int x;cin >> x;
		if(x >= 2) ans ++;
	}
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
	
	while(T --) solve();
	return 0;
}
