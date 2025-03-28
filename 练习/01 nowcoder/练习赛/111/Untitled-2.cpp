#include <bits/stdc++.h>
#define debug(x) cout << #x << "=" << x << "\n";
using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e6 + 10;

int n;
int a[N];


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		int gc = __gcd(sum, i);
		pii p_now = {sum/gc, i/gc};
		
//		debug(p_now.first)
//		debug(p_now.second)
		
		int l = 1, r = i + 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (a[mid] * p_now.second > p_now.first) r = mid;
			else l = mid + 1;
		}
		
		int res = i - l + 1;
		ans = max(res, ans);
		
		sum -= a[i];
	}
	
	cout << ans << "\n";
	
	return 0;
}
