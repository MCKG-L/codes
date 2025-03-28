#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin >> s) {
    s.erase(
      unique(s.begin(), s.end(), [&] (char &x, char &y) {
        return x == y and x == 'x';
      }),
      s.end()
    );
    cout << s << endl;
  }
  return 0;
}