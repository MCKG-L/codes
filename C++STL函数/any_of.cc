#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//范围为空返回false！
//只要范围内有一个满足测试条件则为true，否则返回false
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  while (cin >> n) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    int m;
    cin >> m;
    cout << (any_of(a.begin(), a.end(), [&](int &x) {return x == m;}) ? "^_^" : "-_-||");
   
  }
  return 0;
}