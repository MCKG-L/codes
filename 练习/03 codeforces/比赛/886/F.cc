#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    map<int,int> mp;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mp[x] ++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=i/j;j++){
            if(i % j) continue;
            cnt += mp[j];
            if(j != i / j) cnt += mp[i/j];
        }
        ans = max(ans,cnt);
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