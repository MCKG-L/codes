#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    vector<int> a(n);
    set<set<int>> ans;
    iota(a.begin(), a.end(), 1); // 顺次赋值
    //第三个参数是开始的第一个值
    do {
      ans.emplace(set<int>(a.begin(), a.begin() + m));
    } while (next_permutation(a.begin(), a.end()));
    cout << ans.size() << endl;
    for (auto &s : ans) {
      for (auto it = s.begin(); it != s.end(); it ++) {
        cout << *it << " \n"[it == prev(s.end())];
      }
    }

  }
  return 0;
}