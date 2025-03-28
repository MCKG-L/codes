#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
/*
1、在头文件 algorithm（算法）中
2、有三个参数，其中第三个参数cmp（排序准则）是可选的
3、第三个参数如果是greater<int>()则是从大到小排序
也可以自定义bool类型的函数：
bool cmp(int x,int y){
    return x % 10 < y % 10;
}
sort(a,a+10,cmp);//按照数组中元素的个位数从小到大排序

cmp可以是lambda表达式形式
  int a[5] = {13,11,110,156,131};
  sort(a,a+5,[&](int x,int y){return x%10 < y%10;});
  for(int i : a) cout << i << " ";

*/
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> a(n, vector<int>(m));
    //输入
    for (auto &s : a) {
      for (auto &i : s) {
        cin >> i;
      }
    }
    sort(a.begin(), a.end());//排序
    //输出
    for (auto &s : a) {
      for (int i = 0; i < m; i ++) {
        cout << s[i] << " \n"[i == m - 1];
      }
    }
  }
//   int a[5] = {13,11,110,156,131};
//   sort(a,a+5,[&](int x,int y){return x%10 < y%10;});
//   for(int i : a) cout << i << " ";
  return 0;
}