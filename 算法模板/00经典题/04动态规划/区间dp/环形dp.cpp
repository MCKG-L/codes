#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 1e5 + 10;
/*abc_400_f
环形区间dp
给出一个环形的数组，初始颜色为0，可以执行下面的操作任意次：
选择一个长度为len的连续区间，并将这个区间的颜色都变为c,操作代价为len+X[c]
每种颜色的代价为X[c]
问将整个数组染色为指定的颜色序列C(1<=C[i]<=n)，所需要的最小代价
dp[l][r]表示将区间[l,r]染色为指定序列所需要的最小代价
f[l][r]表示最后一次操作区间是[l,r]时的最小操作代价(不包含最后一次操作)
两种转移:
1、直接由分界点转移：dp[l][r] = min(dp[l][r],dp[l][k]+dp[k+1][r])
2、最后一次操作区间是[l,r] dp[l][r] = min(dp[l][r],f[l][r]+len+X[C[l]])
维护f[l][r] 条件是C[l] == C[r],两种转移：
1、直接由[l+1,r-1]转移过来，f[l][r] = min(f[l][r],dp[l+1][r-1])
2、由C[k]==C[l]的点转移：此时相当于只需要将[l+1~k-1]和[k+1~r-1]满足即可
f[l][r] = min(f[l][r],f[l][k]+f[k][r])
*/
void solve(){
    int n;cin >> n;
    vector<int> C(n + 1);
    for(int i=0;i<n;i++) cin >> C[i];
    vector<int> X(n + 1);
    for(int i=1;i<=n;i++) cin >> X[i];
    vector<vector<int>> dp(n + 1,vector<int>(n + 1,inf)),f(n + 1,vector<int>(n + 1,inf));
    for(int i=0;i<n;i++){
        dp[i][i] = 1 + X[C[i]];
        f[i][i] = 0;
    }
    for(int len=2;len<=n;len++){
        for(int l=0;l<n;l++){
            int r = (l + len - 1) % n;
            for(int k=1;k<len;k++){
                int m = (l + k - 1) % n;
                dp[l][r] = min(dp[l][r],dp[l][m]+dp[(m+1)%n][r]);
            }
            if(C[l] == C[r]){
                if(len > 2) f[l][r] = min(f[l][r],dp[(l+1)%n][(r-1+n)%n]);
                else f[l][r] = 0;
                for(int k=l;;k=(k+1)%n){
                    if(C[k] == C[l]) f[l][r] = min(f[l][r],f[l][k]+f[k][r]);
                    if(k == r) break;
                }
                dp[l][r] = min(dp[l][r],f[l][r]+len+X[C[l]]);
            }
        }
    }
    int ans = inf;
    for(int i=0;i<n;i++){
        ans = min(ans,dp[i][(i+n-1)%n]);
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