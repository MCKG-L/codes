#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
void solve(){
    int n;cin >> n;
    bool f = 1;
    int ans = 1,mod = 1e9 + 7;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(a[i] <= i){
            f = 0;break;
        }
        ans = ans * (a[i] - i) % mod;
    }
    if(f) cout << ans << endl;
    else cout << 0 << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}