#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1,vector<int>(5002,0));
    for(int i=a[1];i<=5000;i++){
        dp[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        int x = a[i];
        for(int k=1;k<=5000;k++){
            dp[i][k] = k >= x ? dp[i-1][k] + 1 : dp[i-1][k];
        }
    }
    while(m --){
        int l,r,x;
        cin >> l >> r >> x;
        cout << dp[r][x] - dp[l-1][x] << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}