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
    partition(a.begin(), a.end(), [&](int x) {return x & 1;});
    //partition作用：将容器的数据按照某个条件分为左右两部分
    /*
    1、第三个参数是lambda类型，函数表明了分割条件，满足条件的在左边
    */
    for (int i = 0; i < n; i ++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}