#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    reverse(s.begin(),s.end());
    int ans = 0,l = 0,r = 0;
    for(l=0;l<n && r<n;l++){
        if(s[l] == '1'){
            r = max(r,l);
            while(r < n && s[r] == '1') r ++;
            if(r == n) break;
            swap(s[r],s[l]);
            ans += r - l;
        }
        cout << ans << ' ';
    }
    for(;l<n;l++) cout << -1 << ' ';
    cout << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}