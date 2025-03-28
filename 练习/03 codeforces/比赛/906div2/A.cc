#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mp[x] ++;
    }
    if(mp.size() > 2){
        cout << "No" << endl;
        return;
    }
    if(mp.size() == 1){
        cout << "Yes" << endl;
        return;
    }
    auto [x1,y1] = *mp.begin();
    auto [x2,y2] = *prev(mp.end());
    // cout << x1 << ' ' << y1 << endl;
    // cout << x2 << ' ' << y2 << endl;

    if(n & 1){
        if(max(y1,y2) >= (n + 1) / 2 && min(y1,y2) >= n / 2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        if(y1 == n / 2 && y2 == n / 2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}