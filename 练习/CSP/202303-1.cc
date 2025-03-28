#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n,X,Y;
void solve(){
    cin >> n >> X >> Y;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x = min(X,x2) - max(0ll,x1);
        int y = min(Y,y2) - max(0ll,y1);
        if(x >= 0 && y >= 0) ans += x * y;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}