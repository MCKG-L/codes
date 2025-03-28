#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int n,x,y;
    cin >> n >> x >> y;
    int lcm  = x * y / __gcd(x,y);
    int cnt1 = n / x - n / lcm;
    int cnt2 = n / y - n / lcm;
    int ans = (n+n-cnt1+1)*cnt1/2 - (1+cnt2)*cnt2/2;
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}