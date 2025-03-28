#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    if (prev_permutation(a.begin(), a.end())) {
      for (int i = 0; i < n; i ++) {
        cout << a[i] << " \n"[i == n - 1];
      }
    } else {
      cout << "-\n";
    }
  }
  return 0;
}