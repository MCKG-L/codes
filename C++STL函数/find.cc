#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、在头文件 algorithm 中
2、find()为按值在范围[first,last)中查找，三个参数，前两个指明范围的迭代器，第三个是数值
3、返回值：如果找到，则返回指向首先出现元素的迭代器，如果找不到，则返回last迭代器
*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //取消cin的同步
  /*
  1、取消之后，不可以再使用scanf、printf、gets等否则会出现玄学错误
  2、取消之后可以加快运行速度
  3、不要再用endl，可以使用宏定义 #define endl '\n'
  */

  int n, x;
  while (cin >> n >> x) {
    vector<int> a(n);//n 表示元素个数
    //增强型for循环
    //加引用&后可以实现修改容器里元素的值
    for (int &i : a) {
      cin >> i;
    }
    auto it = find(a.begin(), a.end(), x);
    //如果找不到，返回尾迭代器，如果找到返回指向待查找元素的迭代器
    cout << (it == a.end() ? -1 : it - a.begin()) << endl;
  }
  return 0;
}