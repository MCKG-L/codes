#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
void solve(){
    int n;cin >> n;
    int m = n*(n-1)/2;
    vector<vector<bool>> f(30,vector<bool>(400));
    for(int i=1;i<=n;i++) f[i][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=1;k<=n-i;k++) f[i+k][j+k*i] = f[i][j] | f[i+k][j+k*i];
        }
    }
    int ans = 0;
    for(int i=0;i<=m;i++){
        if(f[n][i]) ans ++;
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