#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    int ans = -1;
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++){
        int k;cin >> k;
        a[i].resize(k);
        for(int j=0;j<k;j++){
            cin >> a[i][j];
        }
    }
    int k;cin >> k;
    for(int i=0;i<n;i++){
        int m = a[i].size();
        if(k >= m) ans = max(ans,a[i][m-1]);
        else ans = max(ans,a[i][k-1]);
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