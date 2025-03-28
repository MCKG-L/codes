#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m,r;
void solve(){
    cin >> n >> m >> r;
    vector<vector<vector<bool>>> dp(n+1,vector<vector<bool>>(m+1,vector<bool>(r+2,0)));
    vector<set<int>> a(n+1),b(m+1);
    for(int i=0;i<r;i++){
        int t,d,x;
        cin >> t >> d >> x;
        if(d == 1) a[x].insert(t);//记录每一行被攻击的时间
        if(d == 2) b[x].insert(t);
    }
    int t = min((a[0].lower_bound(1) == a[0].end() ? r+1 : *a[0].lower_bound(1)),
    (b[0].lower_bound(1) == b[0].end() ? r+1 : *b[0].lower_bound(1)));
    for(int i=0;i<=t;i++) dp[0][0][i] = 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=r;k++){
                int t1 = a[i].lower_bound(i+j+k) == a[i].end() ? r + 1 : *a[i].lower_bound(i+j+k)-i-j;
                int t2 = b[j].lower_bound(i+j+k) == b[j].end() ? r + 1 : *b[j].lower_bound(i+j+k)-i-j;
                int t = min(t1,t2);
                if(t == k) dp[i][j][k] = 0;//k 时刻会被攻击 该时刻不能到达(i,j)
                else{
                    if(i > 0 && dp[i-1][j][k]) dp[i][j][k] = 1;
                    if(j > 0 && dp[i][j-1][k]) dp[i][j][k] = 1;
                    if(k > 0 && dp[i][j][k-1]) dp[i][j][k] = 1;
                }
            }
        }
    }
    for(int i=0;i<=r;i++){
        if(dp[n][m][i]){
            cout << n + m + i << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}