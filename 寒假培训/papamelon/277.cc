#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  while (cin >> n >> x) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    auto it = upper_bound(a.begin(), a.end(), x);
    //upper_bound  > ,不存在返回尾迭代器
    cout << (it == a.end() ? -1 : it - a.begin()) << endl;
  }
  return 0;
}