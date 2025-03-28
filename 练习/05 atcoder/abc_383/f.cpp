#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
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