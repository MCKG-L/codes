#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 4e6 + 10,mod = 998244353,inf = 1e18;
/*abc_402_e
相当于概率01背包
有n个物品，背包容量为m，每个物品有一个价值、体积、价值生效的概率，每种物品只会计算一次价值
求背包能装的物品的最大价值期望
n的范围很小，维护状态集合使用状态压缩
dp[i][s]表示不超过i的体积，装的物品集合为s的最大价值期望
dp[i][s] = max(dp[i][s],p[j]*(dp[i-v[j]][s-(1<<j)]+w[j])+(1-p[j])*dp[i-v[j]][s]);
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<double> p(n + 1);
    vector<int> w(n + 1),v(n + 1);
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
        int x;cin >> x;
        p[i] = x / 100.00;
    }
    vector<vector<double>> dp(m + 1,vector<double>(1<<n|1));
    double ans = 0.0;
    for(int s=0;s<1<<n;s++){
        for(int i=0;i<n;i++){
            if((s >> i & 0x1) == 0) continue;
            for(int j=v[i+1];j<=m;j++){
                dp[j][s] = max(dp[j][s],p[i+1]*(dp[j-v[i+1]][s-(1<<i)]+w[i+1])+(1-p[i+1])*dp[j-v[i+1]][s]);
                ans = max(ans,dp[j][s]);
            }
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
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