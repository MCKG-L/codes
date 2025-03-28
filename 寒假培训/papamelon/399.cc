#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  while (cin >> n >> x >> y) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    auto it = find_if(a.begin(), a.end(), [&](int &v){return x <= v and v <= y;});
    cout << (it == a.end() ? -1 : it - a.begin()) << endl;
  }
  return 0;
}