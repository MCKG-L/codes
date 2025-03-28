#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e3 + 10,mod = 998244353;
typedef pair<int,int> PII;
/*
f[i][j]表示考虑前i个字母组成密码长度为j的总方案数
*/
int dp[30][N];
int n,m;
int cnt[30],a[30];
void solve(){
    cin >> n >> m;
    for(int i=1;i<=26;i++) cin >> a[i];
    string s;cin >> s;
    for(int i=0;i<s.size();i++){
        cnt[s[i]-'a'+1] ++;
    }
    for(int i=1;i<=26;i++){
        if(cnt[i] > a[i]){
            cout << "NO SOLUTION!" << endl;
            return;
        }
    }
    dp[0][0] = 1;
    for(int i=1;i<=26;i++){
        for(int j=0;j<=m;j++){
            for(int k=cnt[i];k<=min(a[i],m-j);k++){
                dp[i][j+k] += dp[i-1][j];
                dp[i][j+k] %= mod;
            }
        }
    }
    cout << dp[26][m] << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}