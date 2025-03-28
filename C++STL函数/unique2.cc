#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//第三个参数可以是lambda表达式形式的谓词，实现广义的去重
//该程序实现删除字符串中相邻重复的字符x
int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);
  string s;
  while (cin >> s) {
    s.erase(
      unique(s.begin(), s.end(), [&] (char &x, char &y) {
        return x == y and x == 'x';
      }),
      s.end()
    );
    cout << s << endl;
  }
  return 0;
}