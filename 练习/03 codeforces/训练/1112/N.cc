#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 10010,M = 1e5 + 10;
void solve(){
    char a,b;
    cin >> a >> b;
    int s = a - 'A' + b - 'A';
    string ans;
    ans += s % 26 + 'A';
    s /= 26;
    if(s > 0) ans += s + 'A';
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
}
signed main()
{
    IOS;
	int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}