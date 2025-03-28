#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
//只要范围内全部都不满足测试条件时返回为true，否则返回false
//范围为空返回true
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