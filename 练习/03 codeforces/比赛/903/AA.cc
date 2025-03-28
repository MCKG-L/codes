#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int n,m;
void solve(){
    string x,s;
    cin >> n >> m;
    cin >> x >> s;
    // if(x == s){
    //     cout << 0 << endl;
    //     return;
    // }
    int ans = 0;
    while(1){
        // ans ++;
        // x = x + x;
        for(int i=0;i<x.size();i++){
            if(x.substr(i,m) == s){
                cout << ans << endl;
                return;
            }
        }
        if(x.size() > 50) break;
        x = x + x;
        ans ++;
    }
    cout << -1 << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}