#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
/* 题目来源：abc_394_f
烷烃的定义：一颗节点的度数只包含1或4的无向树（至少有一个度数为4的节点）
给定一棵树，求这颗树的属于烷烃的导出子树的最大节点数

思路：树形dp，考虑子节点如何影响父节点，发现只有当子节点v的度数是0或3时，才能成为u的子节点
v的度数为0说明是孤立点，v的度数为3说明v存在3个儿子
满足此条件时，则可以考虑让v成为u的子节点 类似于背包的处理方式

dp[u][i]表示以u为根且u的度数为i时，可以形成的最大烷烃 答案即为max(dp[u][1],dp[u][4])
dp[u][1]代表u作为烷烃的叶子节点，dp[u][4]代表u作为烷烃的非叶子节点
状态转移：
dp[u][i] = max(dp[u][i],dp[u][i-1]+max(dp[v][0],dp[v][3]));
注意i从大到小枚举(相当于一维背包的处理)，避免覆盖
*/
void solve(){
    int n;cin >> n;
    vector<vector<int>> a(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ans = -1;
    int inf = 1e9;
    vector<vector<int>> dp(n+1,vector<int>(10,-inf));
    function<void(int,int)> dfs = [&](int u,int f)->void{
        dp[u][0] = 1;
        for(auto v : a[u]){
            if(v == f) continue;
            dfs(v,u);
            for(int i=4;i>=1;i--){
                dp[u][i] = max(dp[u][i],dp[u][i-1]+max(dp[v][0],dp[v][3]));
            }
            if(dp[u][1] >= 5) ans = max(ans,dp[u][1]); 
            ans = max(ans,dp[u][4]);
        }
    };
    dfs(1,0);
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