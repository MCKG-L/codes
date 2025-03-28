#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
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
    //范围为空返回false！

  }
  return 0;
}