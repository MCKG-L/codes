#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    int n,m,k,H;
    cin >> n >> m >> k >> H;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        int d = abs(H-x);
        if(d % k) continue;
        if(d/k >= 1 && d/k <= m-1) ans ++;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}