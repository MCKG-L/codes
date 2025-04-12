#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int inf = 1e18;
void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a.begin()+1,a.begin()+1+n);
	int ans = inf;
	// for(int i=1;i<n;i++) ans = min(ans,a[i+1]*a[i+1]-a[i]*a[i]);
	for(int i=1;i+m-1<=n;i++){
		int j = i + m - 1;
		ans = min(ans,a[j]*a[j]-a[i]*a[i]);
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
//	cin >> T;
	while(T --) solve();
	return 0;
}
