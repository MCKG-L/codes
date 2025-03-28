#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    vector<int> x(n+1),a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i] >> x[i];
    }
    int ans = 0;
    for(int i=0;i<=23;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            int l = i + x[j];
            int r = i + x[j] + 1;
            if(l >= 24){
                l %= 24,r %= 24;
            }
            if(l >= 9 && r <= 18) cnt += a[j];
        }
        ans = max(ans,cnt);
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