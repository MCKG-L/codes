#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//该程序实现找到给定序列的下一个序列
/*
1、在头文件 algorithm 中
2、两个参数，指明参与序列比较的范围
3、返回值：如果存在下一个序列，则返回true，如果已经是最大的序列，则返回flase，并进行升序排序
*/

//避免输出行末空格的做法：使用 字符数组[下标]
/*
// cout << a[i] << " \n"[i == n - 1];
如果满足i==n-1，则表达式值为1，即为'\n'
如果不满足i==n-1，则表达式值为0，即为' '
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
    if (next_permutation(a.begin(), a.end())) {
      for (int i = 0; i < n; i ++) {
        cout << a[i] << " \n"[i == n - 1];
      }
    } else {
      cout << "-\n";
    }
  }
  return 0;
}