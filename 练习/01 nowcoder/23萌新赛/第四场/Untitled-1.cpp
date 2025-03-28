// Problem: C - Find it!
// Contest: AtCoder - Toyota Programming Contest 2023#4（AtCoder Beginner Contest 311）
// URL: https://atcoder.jp/contests/abc311/tasks/abc311_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<ll, ll> pii;

const int maxn = 200100;

int n, a[maxn], b[maxn];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int u = 1;
	do {
		++b[u];
		u = a[u];
	} while (b[u] <= 1);
	vector<int> ans;
	int x = u;
	do {
		ans.pb(u);
		u = a[u];
	} while (u != x);
	printf("%d\n", (int)ans.size());
	for (int x : ans) {
		printf("%d ", x);
	}
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}