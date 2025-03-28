#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、使用max_element函数应该包含头文件 algorithm
2、返回值：指向范围[first,last)内（若含多个则首个）最小元素的迭代器
3、若范围为空，则返回last迭代器
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
    cout << *min_element(a.begin(), a.end()) << endl;
    //找到容器中最小元素
  }
  return 0;
}