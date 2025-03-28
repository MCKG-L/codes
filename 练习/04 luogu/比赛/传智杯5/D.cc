#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    if(k + 1 >= n){
        cout << 0 << endl;
        return;
    }
    int ans = 1e18;
    sort(a.begin(),a.end());
    for(int i=0;i<=k;i++){
        int m = a[i];
        int M = a[n-1-max(0ll,k-i-i)];
        ans = min(ans,M-m);
    }
    for(int i=0;i<=k;i++){
        int M = a[n-1-i];
        int m = a[max(0ll,k-i-i)];
        ans = min(ans,M-m);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}