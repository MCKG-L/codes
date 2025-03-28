#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    // map<int,int> mp1,mp2;
    // int x,y;cin >> x >> y;
    // for(int i=2;i<=x/i;i++){
    //     while(x % i == 0) mp1[i] ++,x /= i;
    // }
    // if(x > 1) mp1[x] ++;
    // // for(auto i : mp1){
    // //     cout << i.first << ' ' << i.second << endl;
    // // }
    // for(int i=2;i<=y/i;i++){
    //     while(y % i == 0) mp2[i] ++,y /= i;
    // }
    // if(y > 1) mp2[y] ++;
    // int ans = 1;
    // for(auto [x,y] : mp1){
    //     if(mp2.count(x) == 0) continue;
    //     int t = min(y,mp2[x]);
    //     for(int i=0;i<t;i++) ans *= x;
    // }
    // cout << ans << endl;
    int x,y;cin >> x >> y;
    cout << __gcd(x,y) << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}