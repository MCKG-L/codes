#include <iostream>
/*
背景和01背包问题相同
求最优方案的数目 对1e8 + 9 取模
*/

using namespace std;
const int N = 1010,mod = 1e9 + 7,INF = 1e6;
int n,m;
int dp[N],g[N];

int main()
{
    cin >> n >> m;
    g[0] = 1;
    for(int i=1;i<=n;i++) dp[i] = -INF;
    for(int i=0;i<n;i++){
        int v,w;
        cin >> v >> w;
        for(int j=m;j>=v;j--){
            int t = max(dp[j],dp[j-v]+w);
            int s = 0;
            if(t == dp[j]) s += g[j];
            if(t == dp[j-v]+w) s += g[j-v];
            s %= mod;
            dp[j] = t;
            g[j] = s;
        }
    }
    int max_n = 0,ans = 0;
    for(int i=0;i<=m;i++) max_n = max(max_n,dp[i]);
    for(int i=0;i<=m;i++){
        if(max_n == dp[i]){
            ans += g[i];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}