#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int d = abs(a-b);
    c *= 2;
    int k = 0;
    if(d % c == 0) k = d / c;
    else k = d / c + 1;
    cout << k << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}