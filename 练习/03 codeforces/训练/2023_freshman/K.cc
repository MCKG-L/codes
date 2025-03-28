#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 60;
int f[N];
void solve(){
    vector<int> a(10);
    for(int i=1;i<=6;i++) cin >> a[i];
    int ans = 0;
    int t = min(a[1],a[4]);a[1] -= t,a[4] -= t,ans += t;
    t = min(a[2],a[5]);a[2] -= t,a[5] -= t,ans += t;
    t = min(a[3],a[6]);a[3] -= t,a[6] -= t,ans += t;
    ans += min({a[1],a[2],a[3]});
    ans += min({a[4],a[5],a[6]});
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}