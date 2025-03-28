#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
using ldd = long double;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
/* 题目来源：abc_382_e
有一种卡包，里面有n张卡牌，其中第i个卡牌是稀有卡的概率为pi%,问获得至少x张稀有卡
需要拆包的数目期望

设 dp[i]​ 为获得至少 i 张稀有卡的概率,g[i] 为在单个卡包中获得恰好 i 张卡的概率。
则
dp[i] = 1 + ∑[j=0,n]dp(i-j) * g[j]
当j=0使 右边式子中包括dpi*g[0]项，无法转移得到。所以将j=0提取出来并移项到左边得到：
dp[i] = 1 + ∑[j=1,n]dp(i-j) * g[j] + dp[i]*g[0]
即：dp[i] = ∑[j=1,n]dp(i-j) * g[j] / (1 - g[0])这样就可以递推出dp[i]

下面考虑求g[i][j]  即当前考虑到第i个卡牌恰好得到j张稀有牌的概率
明显：g[i][j] = g[i-1][j-1] * p[i] + g[i-1][j] * (1-p[i]);
考虑优化掉第一维，则g[i] = g[i-1] * p[i] + g[i] * (1-p[i]);
*/
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