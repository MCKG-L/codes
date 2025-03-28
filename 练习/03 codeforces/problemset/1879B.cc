#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    int p,x;cin >> p >> x;
    bool f = 1;
    for(int i=0;i<n-1;i++){
        int s,e;cin >> s >> e;
        if(s >= p && e >= x) f = 0;
    }
    if(f) cout << p << endl;
    else cout << -1 << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}