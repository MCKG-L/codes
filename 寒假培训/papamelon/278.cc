#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//找到最后一个大于指定值元素的位置
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  while (cin >> n >> x) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    auto it = lower_bound(a.begin(), a.end(), x);
    cout << (it == a.begin() ? -1 : it - a.begin() - 1) << endl;
  }
  return 0;
}