#include <iostream>
using namespace std;
void solve()
{
    int n;cin >> n;
    if(n > 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}