#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int n,k;
    cin >> n >> k;
    map<int,int> mp;
    int cnt = 0;
    bool f = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x % k == 0) f = 1;
        if(x % 2 == 0) cnt ++;
        mp[x] ++;
    }
    if(f){
        cout << "0" << endl;
        return;
    }
    if(k == 4){
        if(cnt >= 2){
            cout << 0 << endl;
            return;
        }
    }
    int ans = 10;
    if(k == 4) ans = 2 - cnt;
    for(auto [x,y] : mp){
        for(int i=x+1;i<=x+5;i++){
            if(i % k == 0) ans = min(ans,i-x);
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}