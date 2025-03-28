#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  while (cin >> s >> t) {
    cout << (set<int>(s.begin(), s.end()) == set<int>(t.begin(), t.end()) ? 1 : 0) << endl;
  }
  return 0;
}