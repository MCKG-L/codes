#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、all_of函数声明在头文件 algorithm 中
2、前两个参数指明范围，第三个参数是测试条件（谓词），如果对于范围内所有元素都返回true，则all_of函数返回true，否则返回false
3、范围为空返回true！
4、第三个参数可以自定义，可以是bool类型的函数，也可以是lambda表达式等
*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    int m;
    cin >> m;
    cout << (all_of(a.begin(), a.end(), [&](int &x) {return x == m;}) ? "^_^" : "-_-||");
    
  }
  return 0;
}