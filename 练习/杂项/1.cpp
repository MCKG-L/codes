#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 2e5 + 10;
void solve(){
	int n,m;cin >> n >> m;
	vector<string> a(n);
	vector<vector<string>> b(m,vector<string>(n));
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++) cin >> b[i][j];
	}
	int Max = -1;
	vector<bool> st(n);
	for(int i=0;i<m;i++){
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(b[i][j] == a[j]){
				cnt ++;
				st[j] = 1;
			}
		}
		Max = max(Max,cnt);
	}
	for(int i=0;i<n;i++){
		if(!st[i]){
			cout << -1 << endl;
			return;
		}
	}
	cout << n + 2 * (n - Max) << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T = 1;
	#ifdef LOCAL
		freopen("D:\\Others\\desktop\\text.in","r",stdin);
	#endif
	cin >> T;
	while(T --) solve();
	return 0;
}