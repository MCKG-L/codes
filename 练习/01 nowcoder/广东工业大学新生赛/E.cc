#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    map<int,int> mp;
    mp[0] = 0;
    int sum = 0,ans = 0;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        if(x == 1) sum ++;
        else sum --;
        if(mp.count(sum) == 0) mp[sum] = i;
        ans = max(ans,i-mp[sum]);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}