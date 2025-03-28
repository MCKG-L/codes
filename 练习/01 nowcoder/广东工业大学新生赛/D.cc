#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int x,y;
    cin >> x >> y;
    int cnt1 = 0,cnt2 = 0;
    while(x % 6 == 0) cnt1 ++,x /= 6;
    while(y % 6 == 0) cnt2 ++,y /= 6;
    int ans = 0;
    if(cnt1 < cnt2){
        cout << -1 << endl;
        return;
    }
    ans += cnt1 - cnt2;
    cnt1 = 0,cnt2 = 0;
    while(x % 5 == 0) cnt1 ++,x /= 5;
    while(y % 5 == 0) cnt2 ++,y /= 5;
    if(x != y || cnt1 > cnt2){
        cout << -1 << endl;
        return;
    }
    ans += cnt2 - cnt1;
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}