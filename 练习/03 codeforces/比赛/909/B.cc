#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,M = 5e5 + 10;

void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    int ans = -1;
    for(int x=1;x<=n;x++){
        if(n % x) continue;
        int M = -1,m = 1e18;
        for(int i=1;i<=n/x;i++){
            int p = i * x;
            M = max(M,a[p]-a[p-x]);
            m = min(m,a[p]-a[p-x]);
        }
        ans = max(ans,M-m);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}