#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、__gcd函数在头文件 algorithm 中
2、作用为求两个数的最大公约数并返回
*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T --) {
    int x, y;
    cin >> x >> y;
    cout << __gcd(x, y) << endl;
    //求最大公约数，辗转相除法实现
  }
  return 0;
}