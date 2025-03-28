#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    map<int,int> mp1;
    // map<PII,int> mp2;
    int ans = 0,cnt = 0;
    for(int i=0;i<n;i++){
        int a,b;cin >> a >> b;
        ans += i - mp1[a];
        // if(a == 0) ans -= cnt;
        // ans -= mp2[{a,b}];
        mp1[a] ++;
        // if(a == 0) cnt ++;
    }
    cout << max(0ll,ans) << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}