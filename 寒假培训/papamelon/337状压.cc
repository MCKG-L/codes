#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    int ans = 1;
    for (int i = 1; i <= n; i ++) ans *= i;
    for (int i = 1; i <= m; i ++) ans /= i;
    for (int i = 1; i <= n - m; i ++) ans /= i;
    cout << ans << endl;
    int maxn = 1 << n;
    for (int i = maxn - 1; i >= 0; i --) {
      if (__builtin_popcount(i) != m) continue;
      int cnt = 0;
      for (int j = n - 1; j >= 0; j --) {
        if (i >> j & 1) {
          ++ cnt;
          cout << n - j << " \n"[cnt == m];
        }
      }
    }
  }
  return 0;
}