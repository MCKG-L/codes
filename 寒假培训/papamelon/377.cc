#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
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