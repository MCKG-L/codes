#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、在头文件 numberic 中
2、前三个参数必须：前两个参数指明范围，第三个参数是初始值，第四个参数可选，可以实现连乘
3、第四个参数为multiplies<int>(),可以实现连乘
*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    cout << accumulate(a.begin(), a.end(), 0);
    //accumulate声明在头文件 numeric 中
    //第三个参数是累加的初始值
  }
  return 0;
}