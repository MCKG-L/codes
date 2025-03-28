#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    cout << (any_of(a.begin(), a.end(), [&](int &x) {return x & 1;}) ? "oh, no!" : "good!");
  }
  return 0;
}