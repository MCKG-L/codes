#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
map<int,int> mp[4];
void solve(){
    for(int i=0;i<4;i++) mp[i].clear();
    int n;cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x,y;cin >> x >> y;
        ans += mp[0][x];
        ans += mp[1][y];
        ans += mp[2][x+y];
        ans += mp[3][x-y];
        mp[0][x] ++,mp[1][y] ++;
        mp[2][x+y] ++,mp[3][x-y] ++;
    }
    cout << ans*2 << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}