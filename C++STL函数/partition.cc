#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、在头文件 algorithm 中
2、前两个参数指明范围，第三个参数是bool类型函数，可以是lambda表达式
3、第三个参数是一个bool类型的函数，指明了分类的标准，满足条件的在左侧
4、返回值：返回指向第一个不满足分类条件元素的迭代器
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
    partition(a.begin(), a.end(), [&](int x) {return x % 2 == 1;});
    //partition作用：将容器的数据按照某个条件分为左右两部分
    /*
    1、第三个参数可以是lambda类型，函数表明了分割条件，满足条件的在左边
    */
    for (int i = 0; i < n; i ++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}