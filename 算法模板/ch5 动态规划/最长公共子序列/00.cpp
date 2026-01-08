#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e3 + 10,M = 1e5 + 10;
/*
给出两个字符串，求最长公共子序列长度
*/
void solve(){
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    a = ' ' + a,b = ' ' + b;
    vector<vector<int>> dp(n + 1,vector<int>(m + 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << endl;
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
