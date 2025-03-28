#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int, int> PII;
const int N = 1e6+10;
int arr[N];
int book[N];
int cnt;
void f() {
	for (int i = 2; i <= 1e6; i++) {
		if (!book[i])arr[++cnt] = i;
		for (int j = 1; j <= cnt && 1ll*i * arr[j] <= 1e6; j++) {
			book[i * arr[j]] = 1;
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
		for (int j = 1; arr[j] * arr[j] <= x; j++) {
			int temp = arr[j];
			int cnt = 0;
			while (x% temp== 0) {
				x /= temp; cnt++;
			}
			if (cnt) vis[temp]++;
			maxx = max(maxx, vis[temp]);
		}
		if (x > 1)vis[x]++;
		maxx = max(maxx, vis[x]);
	}
	for (int i = 2; i <= 1e6; i++) {
		if (vis[i] == maxx) {
			cout << i << "\n"; return;
		}
	}
}
signed main()
{
	IOS;
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}