#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int ans = 1e9;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int d,s;
        cin >> d >> s;
        ans = min(ans,d+(s-1)/2);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}