#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、该函数时c++自带的库函数
2、作用是统计一个数字在二进制状态下1的个数并返回
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T --) {
    int x;
    cin >> x;
    cout << __builtin_popcount(x) << endl;
    //该函数用来统计一个数二进制形式中1的个数
  }
  return 0;
}