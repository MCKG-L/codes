#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10,mod = 1e9 + 7;
typedef pair<int,int> PII;
/*
2
2 1 2
1 1
2
*/
void solve(){
    int n;cin >> n;
    vector<vector<int>> a(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        int k;cin >> k;
        sum += k;
        a[i].resize(k+1,0);
        for(int j=1;j<=k;j++){
            cin >> a[i][j];
        }
    }
    int k;cin >> k;
    int ans = 0;
    for(int i=0;i<n;i++){
        int len = a[i].size() - 1;
        int m = max(0ll,k + len - sum);
        int M = min(k,len);
        for(int j=m;j<=M;j++){
            ans = (ans + a[i][j]) % mod;
        }
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