#include <bits/stdc++.h>
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int, int> PII;
const int N = 1e6+10;
int p[N];
int arr[N];
int book[N];
int cnt;
void f() {
	for (int i = 2; i <= 1e6; i++) {
		if (!book[i])arr[++cnt] = i, p[i] = i;
		for (int j = 1; j <= cnt && 1ll*i * arr[j] <= 1e6; j++) {
			book[i * arr[j]] = 1;
			p[i * arr[j]] = arr[j];
			if (i % arr[j] == 0)break;
		}
	}
}
void solve() {
	f();
	int n; cin >> n;
	vector<int>a(n + 10);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int>vis(1e6 + 10);
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		while (p[x]) {
			int temp = p[x]; int cnt = 0;
			while (x % temp == 0) {
				x /= temp; cnt++;
			}
			if (cnt) vis[temp]++;
			maxx = max(maxx, vis[temp]);
		}
	}
	for (int i = 2; i <= 1e6; i++) {
		if (vis[i] == maxx) {
			cout << i << "\n"; return;
		}
	}
}
signed main()
{
	IOS; int T = 1;
	// cin >> T;

	while (T--) solve();
	return 0;
}