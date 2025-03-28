#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
void solve(){
    int n,p,q;
    cin >> n >> p >> q;
    int m = 1e5;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        m = min(m,x);
    }
    cout << min(p,m+q) << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}