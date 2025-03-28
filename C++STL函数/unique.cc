#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、unique函数 在头文件 algorithm 中
2、实际上实现的是相邻元素的去重，所以使用前应该先排序
3、返回值：返回指向不重复序列元素的下一个元素的迭代器
3、单独使用并不可以实现删除，只是把不重复元素移到前面了
4、与函数erase结合使用可以实现真正的去重
5、n = unique(a.begin(),a.end()) - a.begin() 得到不重复序列的长度
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
    sort(a.begin(), a.end());
    n = a.erase(unique(a.begin(), a.end()), a.end()) - a.begin();
    for(int i = 0; i < n; i ++) {
      cout << a[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;
// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);
//   int n, x;
//   while (cin >> n) {
//     set<int> s;
//     //利用set的元素互异性
//     while (n --) {
//       cin >> x;
//       s.emplace(x);
//     }
//     for (auto it = s.begin(); it != s.end(); it ++) {
//       cout << *it << " \n"[it == prev(s.end())];
//     }
//     //避免行末空格的方法：字符数组[下标]
//     //如果满足条件，则为[1],即为'\n',如果不满足条件，则为[0],即为' ';
//   }
//   return 0;
// }