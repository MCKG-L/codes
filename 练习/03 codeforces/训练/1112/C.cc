#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 10010,M = 1e5 + 10;
void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i=0;i<n-1;i++){
        if(abs(a[i]-a[i+1]) > 1) ans ++;
    }
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