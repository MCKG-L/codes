#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int x,y,k;
    cin >> x >> y >> k;
    if(x >= y){
        cout << x << endl;
        return;
    }
    int x1 = min(x+k,y);
    int ans = x1;
    if(x1 < y) ans += (y-x1)*2;
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