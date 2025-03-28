#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T --) {
    int x, y;
    cin >> x >> y;
    cout << __gcd(x, y) << endl;
    //求最大公约数，辗转相除法实现
  }
  return 0;
}