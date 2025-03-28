#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
const int N = 2e5 + 10;
typedef pair<int,int> PII;
using ll = long long;
struct Node{
    int k,c,val;
    bool operator> (const Node &f)const{
        return val < f.val;
    }
};
void solve(){
    int n,m;    
    cin >> n >> m;
    vector<vector<int>> dp[4];//三种维生素分别考虑，
    //贪心的想，摄入维生素i最大的情况一定只摄入含i的食物，不会重复
    vector<int> a(n+1),b(n+1),c(n+1);//a是种类
    for(int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
    for(int i=1;i<=3;i++) dp[i].resize(n+10,vector<int>(m+10,0));
    for(int k=1;k<=3;k++){
        for(int i=1;i<=n;i++){
            if(a[i] != k){
                dp[k][i] = dp[k][i-1];
                continue;
            }
            for(int j=0;j<=m;j++){
                dp[k][i][j] = dp[k][i-1][j];
                if(j >= c[i]) dp[k][i][j] = max(dp[k][i][j],dp[k][i-1][j-c[i]]+b[i]);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;i+j<=m;j++){
            ans = max(ans,min({dp[1][n][i],dp[2][n][j],dp[3][n][m-i-j]}));
        }
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