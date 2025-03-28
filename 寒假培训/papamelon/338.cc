#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> a(n, vector<int>(m));
    //输入
    for (auto &s : a) {
      for (auto &i : s) {
        cin >> i;
      }
    }
    sort(a.begin(), a.end());//排序
    //输出
    for (auto &s : a) {
      for (int i = 0; i < m; i ++) {
        cout << s[i] << " \n"[i == m - 1];
      }
    }
  }
  return 0;
}