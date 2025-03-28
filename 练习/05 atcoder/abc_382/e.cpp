#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
using ldd = long double;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<ldd> a(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];a[i] /= 100;
    }
    // vector<vector<ldd>> g(n + 1,vector<ldd>(n + 1));dp[i][j]前i个卡牌得到j个稀有卡的概率
    vector<ldd> g(n + 1);
    g[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            g[j] = g[j] * (1- a[i]) + g[j-1] * a[i];
        }
        g[0] *= (1 - a[i]);
    }
    vector<ldd> dp(m + 1);//获得i张稀有卡的拆包数期望
    for(int i=1;i<=m;i++){
        dp[i] = 1;
        for(int j=1;j<=n;j++){
            dp[i] += dp[max(0ll,i-j)] * g[j];
        }
        dp[i] /= (1 - g[0]);
    }
    cout << fixed << setprecision(15);
    cout << dp[m] << endl;
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