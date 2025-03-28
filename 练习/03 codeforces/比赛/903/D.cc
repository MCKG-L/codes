#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
void solve(){
    map<int,int> mp;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        for(int j=2;j<=x/j;j++){
            while(x % j == 0){
                mp[j] ++;x /= j;
            }
        }
        if(x > 1) mp[x] ++;
    }
    bool f = 1;
    for(auto [x,y] : mp){
        if(y % n){
            f = 0;
            break;
        }
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}