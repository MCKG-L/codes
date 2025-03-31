#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e18;
const int N = 5e5 + 10;
/* 题目来源：abc_380_f
Takahashi 和 Aoki 在玩一个卡牌游戏，每张卡牌上写有一个数字。
初始时 Takahashi 有 N 张牌，Aoki 有 M 张牌，桌上还有 L 张牌。游戏规则如下：
1、轮到某个玩家的回合时，该玩家需从手中打出一张牌（记作 k）置于桌子上，并允许从桌子上拿取不超过一张数值小于 k 的牌。
2、当一个玩家不能进行上述操作时，对方获胜，游戏结束。
若 Takahashi 先手，双方都知道所有牌的布局，问最优策略下谁是必胜者。
N+M+L≤12

数据范围很小，可以考虑状态压缩+爆搜
可以根据每张卡牌的所属描述每一张卡牌，所以使用一个三进制位表示第i张卡牌所在的位置
轮到每一个选手时，可以枚举可以打出哪一张牌以及从桌子上拿起哪一张牌，考虑下一轮选手是否有必胜策略
如果存在某一种选取方案，使得下一轮对方出现必败局面，则现局面就是必胜局面。
注意打出和拾取之后当前卡牌局面的计算：三进制
*/
void solve(){
    int n,m,l;
    cin >> n >> m >> l;
    vector<int> a(n + m + l);
    for(auto &x : a) cin >> x;
    vector<int> pw(n + m + l + 1);
    pw[0] = 1;
    //三进制状态压缩 对于每一张牌0表示在A手中，1表示在B手中，2表示在桌子上
    int S = 0;
    for(int i=1;i<=n+m+l;i++) pw[i] = pw[i-1] * 3;
    for(int i=0;i<n;i++) S += 0 * pw[i];
    for(int i=n;i<n+m;i++) S += 1 * pw[i];
    for(int i=n+m;i<n+m+l;i++) S += 2 * pw[i];
    vector<vector<int>> dp(2,vector<int>(pw[n+m+l],-1));//记忆化搜索
    auto cal = [&pw](int s,int i)->int{
        return s / pw[i] % 3;
    };
    auto dfs = [&](auto dfs,int o,int s)->bool{
        // cerr << o << ' ' << s << endl;
        if(~dp[o][s]) return dp[o][s];
        bool ok = 0;
        for(int i=0;i<n+m+l;i++){
            ok |= cal(s,i) == o;
        }
        if(!ok) return dp[o][s] = 0;
        dp[o][s] = 0;
        for(int i=0;i<n+m+l;i++){
            if(cal(s,i) != o) continue;
            dp[o][s] |= !dfs(dfs,o^1,s-o*pw[i]+2*pw[i]);
            for(int j=0;j<n+m+l;j++){
                if(cal(s,j) != 2 || a[i] <= a[j]) continue;
                dp[o][s] |= !dfs(dfs,o^1,s-o*pw[i]+2*pw[i]+o*pw[j]-2*pw[j]);
            }
        }
        return dp[o][s];
    };
    cout << (dfs(dfs,0,S) ?  "Takahashi" : "Aoki") << endl;
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