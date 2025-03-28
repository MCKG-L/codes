#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
/* 来源：abc_383_f
给n个物品，可一个参数k
每个物品有价值w，价格v，类别c，选择其中的一些物品，求总价格不超过m的情况下，总价值最大
总价值定义为：sum + cnt * k，其中sum为物品价值之和，cnt为选择的物品类别总数，k为给定的参数

考虑当前的物品，如果其类别已经被使用，则可以按照正常的背包转移，如果没有使用，则可获得额外的价值k
定义状态dp[c][j]为选择了前c个类别，总价值不超过m的最大价值
将原物品按照类别排序，使得同类别的在连续的位置

转移方程：该类别已经使用过时：dp[c][j] = max(dp[c][j],dp[c][j-v] + w)
如果该类别第一次使用:dp[c][j] = max(dp[c][j],max(dp[1...c-1][j]) + w + k)
即可以从前c-1个类别状态中转移过来,可以发现max(dp[1...c-1][j])在上一轮中计算过且不变，可以使用一个前缀最大值数组记录
pre[c][j]表示前c个类别，价格不超过j时的最大价值
则dp[c][j] = max(dp[c][j],pre[c-1][j]);

最后更新 pre[c][j] = max(pre[c-1][j],dp[c][j]);

*/
struct Node{
    int v,w,c;
    bool operator<(const Node &p)const{
        return c < p.c;
    }
};
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<Node> a(n + 1);
    for(int i=1;i<=n;i++){
        int v,w,c;
        cin >> v >> w >> c;
        a[i] = {v,w,c};
    }
    sort(a.begin()+1,a.begin()+1+n);
    vector<vector<int>> dp(n + 1,vector<int>(m + 1)),pre(n + 1,vector<int>(m + 1));
    int now = 0,lc = 0;
    for(int i=1;i<=n;i++){
        auto &[v,w,c] = a[i];
        if(lc != c) now ++;//next color
        lc = c;
        for(int j=m;j>=v;j--){
            dp[now][j] = max(dp[now][j-v] + w,dp[now][j]);
            dp[now][j] = max(dp[now][j],pre[now-1][j-v] + w + k);
        }
        for(int j=m;j>=0;j--) pre[now][j] = max(pre[now-1][j],dp[now][j]);
    }
    int ans = -1;
    for(int i=1;i<=now;i++){
        ans = max(ans,dp[i][m]);
    }
    cout << ans << endl;
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