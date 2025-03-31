#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e18;
const int N = 5e5 + 10;
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