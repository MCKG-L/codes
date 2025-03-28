#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
void solve(){
    int n;cin >> n;
    n ++;
    cout << (n * n + 1) << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}