#include <iostream>
#define int long long
#define rep(i, a, n) for(int i=(a);i<=(n);++i)
using namespace std;
const int N = 1e5+10;
int a[N];
void solve()
{
	int n; cin >> n;
	rep(i, 1, n)
	{
		int l, r, tmp;
		cin >> l >> tmp >> r >> tmp;
		a[r] --;
		a[l] ++;
	}
	rep(i, 1, N-5) a[i] += a[i-1];
//	rep(i, 1, n) cout << a[i] << ' ';
	int ans = 0;
	rep(i, 1, N-5) if(a[i]) ans ++;
	cout << ans << endl;
}
signed main()
{
//	int t; cin >> t;
//	while(t--)
	solve();
	return 0;
}