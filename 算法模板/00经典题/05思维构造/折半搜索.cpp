#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 1e5 + 10;
/*abc_402_f
有一个 N 行 N 列的网格。从上往下第 i 行、从左往右第 j 列的格子记作格子 (i,j)。每个格子上都写有 1 到 9 的数字，格子 (i,j) 上写的数字是 Ai,j​。

初始时，棋子位于格子 (1,1)。同时，设 S 为空字符串，接下来进行 2N−1 次操作：

    将当前棋子所在格子的数字追加到 S 的末尾。
    将棋子向右或向下移动一格（第 2N−1 次操作时不移动）。

2N−1 次操作后，棋子将位于格子 (N,N)，且 S 的长度为 2N−1。

将最终得到的字符串 S 视为整数，其值对 M 取模的结果即为得分。

请计算可以获得的最高得分。
搜索一半，到对角线位置保存当前所有的可能值，然后从另一端搜索，到对角线位置贪心更新答案
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1,vector<int>(n + 1)),P(n + 1,vector<int>(n + 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin >> a[i][j];
    }
    int t = 1ll;
    for(int k=n*2;k>=2;k--,t*=10){
        t %= m;
        for(int i=1;i<=n;i++){
            int j = k - i;
            if(j < 1 || j > n) continue;
            P[i][j] = t;
        }
    }
    vector<set<int>> q(n + 1);
    auto dfs1 = [&](auto dfs1,int x,int y,int t){
        if(x + y == n + 1){
            t = (t + a[x][y] * P[x][y]) % m;
            q[x].insert(t);
            return;
        }
        int k = (t+a[x][y]*P[x][y]) % m;
        if(x+1<=n) dfs1(dfs1,x+1,y,k);
        if(y+1<=n) dfs1(dfs1,x,y+1,k);
    };
    dfs1(dfs1,1,1,0);
    int ans = 0;
    auto dfs = [&](auto dfs,int x,int y,int t){
        if(x + y == n + 1){
            int val = t % m;
            auto it = q[x].lower_bound(m-val);
            if(it != q[x].begin()){
                it --;
                ans = max(ans,*it+val);
            }else{
                ans = max(ans,(*prev(q[x].end())+val)%m);
            }
            return;
        }
        if(x-1 >= 1) dfs(dfs,x-1,y,(t+a[x][y]*P[x][y])%m);
        if(y-1 >= 1) dfs(dfs,x,y-1,(t+a[x][y]*P[x][y])%m);
    };
    dfs(dfs,n,n,0);
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