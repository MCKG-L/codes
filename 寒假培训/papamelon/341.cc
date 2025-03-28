#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    char c;
    string opt;
    multiset<char> s;
    while (n --) {
      cin >> opt >> c;
      if (opt == "A") {
        s.emplace(c);
      } else if (opt == "D") {
        if (s.count(c)) {//count返回数字，可以用来判断是否存在，find返回迭代器
          s.erase(s.find(c));
          //An iterator pointing to the element to be erased 只删除一个
        }
      } else if (opt == "DD") {
        s.erase(c);
        //Key of element to be erased 删除所有key值
      } else {
        cout << s.count(c) << endl;
      }
    }
  }
  return 0;
}