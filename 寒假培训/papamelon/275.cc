#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、三个参数，前两个参数指明范围的迭代器，第三个参数是指定的值
2、lower_bound函数返回指向首个不小于指定值元素的迭代器
3、用二分法实现，使用该函数之前应该先排序
4、返回值：如果找到，则返回指向该元素的迭代器，否则返回结束迭代器
*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  while (cin >> n >> x) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    sort(a.begin(),a.end());
    auto it = lower_bound(a.begin(), a.end(), x);
    //lower_bound >= ，不存在返回尾迭代器
    if (it == a.end() or *it > x)  {
      cout << "no";
    } else {
      cout << "yes";
    }
    cout << endl;
  }
  return 0;
}