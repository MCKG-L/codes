#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  while (cin >> n) {
    set<int> s;
    while (n --) {
      cin >> x;
      s.emplace(x);
    }
    for (auto it = s.begin(); it != s.end(); it ++) {
      cout << *it << " \n"[it == prev(s.end())];
    }
    //避免行末空格的方法：字符数组[下标]
    //如果满足条件，则为[1],即为'\n',若不满足则为[0],即为' ';
  }
  return 0;
}
// 方法二
// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);
//   int n;
//   while (cin >> n) {
//     vector<int> a(n);
//     for (int &i : a) {
//       cin >> i;
//     }
//     sort(a.begin(), a.end());
//     n = a.erase(unique(a.begin(), a.end()), a.end()) - a.begin();
//     for(int i = 0; i < n; i ++) {
//       cout << a[i] << " \n"[i == n - 1];
//     }
//   }
//   return 0;
// }