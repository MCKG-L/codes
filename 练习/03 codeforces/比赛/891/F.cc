#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    map<int,int> mp;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mp[x] ++;
    }
    int q;cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        int d = x * x - 4 * y;
        if(d < 0){
            cout << 0 << ' ';
            continue;
        }
        int s = sqrt(d);
        int x1 = (x + s) / 2,x2 = (x - s) / 2;
        if(x1 + x2 != x || x1 * x2 != y){
            cout << 0 << ' ';
            continue;
        }
        if(x1 == x2){
            cout << (mp[x1]*(mp[x1]-1)/2) << ' ';
        }else{
            cout << mp[x1] * mp[x2] << ' ';
        }
    }
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}