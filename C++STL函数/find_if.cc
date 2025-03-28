#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、应包含头文件 algorithm 
2、find_if为按条件查找，前两个参数指明范围的迭代器，第三个参数为_Pred函数或谓词（返回bool类型的仿函数）
3、第三个参数写成lambda表达式形式
*/
int main() {
  int n, x, y;
  while (cin >> n >> x >> y) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    auto it = find_if(a.begin(), a.end(), [&](int &v){return x <= v and v <= y;});
    cout << (it == a.end() ? -1 : it - a.begin()) << endl;
  }
  return 0;
}