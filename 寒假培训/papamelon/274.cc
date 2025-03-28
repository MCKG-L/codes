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
    //反向迭代器
    auto it = find(a.rbegin(), a.rend(), x);
    cout << (it == a.rend() ? -1 : it - a.rbegin()) << endl;
  }
  return 0;
}