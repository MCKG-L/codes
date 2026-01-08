#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 1e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
/*
状态定义：0->XXX 1->XXT 2->XTJ
正着做：dp[i][0/1][j][k]表示考虑到第i个位置，且第i个位置为字符j时，字符串状态为k，且是(1)/否(0)满足限制的方案数
使用滚动数组优化掉第一维
这里需要额外记录不满足条件大的方案数目，因为可以通过状态2转化为满足条件
*/
void solve(){
    string s;cin >> s;
    int n = s.size();
    s = ' ' + s;
    //dp[0/1][j][k] 26*2*3*n 使用滚动数组优化掉第一维
    int m = 26;
    vector<vector<array<int,3>>> dp(2,vector<array<int,3>>(m + 1));
    if(s[1] == '?'){
        for(int i=0;i<m;i++){
            if(i == 'T' - 'A'){
                dp[0][i][1] = 1;
            }else{
                dp[0][i][0] = 1;
            }
        }
    }else{
        if(s[1] == 'T'){
            dp[0][s[1]-'A'][1] = 1;
        }else{
            dp[0][s[1]-'A'][0] = 1;
        }
    }
    vector<int> order(m),oth(1);
    iota(order.begin(),order.end(),0);
    for(int i=2;i<=n;i++){
        vector<vector<array<int,3>>> ndp(2,vector<array<int,3>>(m + 1));
        if(s[i] != '?') oth[0] = s[i] - 'A';
        for(int j=0;j<m;j++){
            for(int now=0;now<2;now++){
                for(auto k : (s[i] == '?' ? order : oth)){
                    if(k == 'T' - 'A'){
                        ndp[now][k][1] += dp[now][j][0] + dp[now][j][1] + dp[now][j][2];
                    }else if(k == 'J' - 'A'){
                        ndp[now][k][2] += dp[now][j][1];
                        ndp[now][k][0] += dp[now][j][0] + dp[now][j][2];
                    }else{
                        ndp[now][k][0] += dp[now][j][1] + dp[now][j][0];
                        if(now == 1 && k == 'U' - 'A'){
                            ndp[now][k][0] += dp[0][j][2];
                        }
                    }
                    ndp[now][k][0] %= mod;
                    ndp[now][k][1] %= mod;
                    ndp[now][k][2] %= mod;
                }
            }
        }
        dp = ndp;
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            ans = (ans + dp[1][i][j]);
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}


// #include <bits/stdc++.h>
// #define int long long
// #define endl '\n'
// using namespace std;
// using i128 = __int128;
// typedef pair<int,int> PII;
// using ll = long long;
// const int N = 1e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
// void solve(){
//     string s;cin >> s;
//     int n = s.size();
//     s = ' ' + s;
//     //1: xxT 2:xTJ
//     vector<array<int,3>> dp(30);
//     if(s[1] == '?'){
//         for(int i=0;i<26;i++){
//             if(i == 'T' - 'A'){
//                 dp[i][1] = 1;
//             }else{
//                 dp[i][0] = 1;
//             }
//         }
//     }else{
//         if(s[1] == 'T') dp['T'-'A'][1] = 1;
//         else dp['T'-'A'][0] = 1;
//     }
//     for(int i=2;i<=n;i++){
//         vector<array<int,3>> ndp(30);
//         for(int j=0;j<26;j++){
//             if(s[i] == '?'){
//                 for(int k=0;k<26;k++){
//                     if(k == 'T' - 'A'){
//                         ndp[k][1] += dp[j][0] + dp[j][1] + dp[j][2];
//                     }else if(k == 'J' - 'A'){
//                         ndp[k][2] += dp[j][1];
//                         ndp[k][0] += dp[j][0] + dp[j][2];
//                     }else{
//                         if(k == 'U' - 'A'){
//                             ndp[k][0] += dp[j][0] + dp[j][1];
//                         }else
//                         ndp[k][0] += dp[j][0] + dp[j][1] + dp[j][2];
//                     }
//                     ndp[k][0] %= mod;
//                     ndp[k][1] %= mod;
//                     ndp[k][2] %= mod;
//                 }
//             }else{
//                 int k = s[i] - 'A';
//                 if(k == 'T' - 'A'){
//                     ndp[k][1] += dp[j][0] + dp[j][1] + dp[j][2];
//                 }else if(k == 'J' - 'A'){
//                     ndp[k][2] += dp[j][1];
//                     ndp[k][0] += dp[j][0] + dp[j][2];
//                 }else{
//                     if(k == 'U' - 'A'){
//                         ndp[k][0] += dp[j][0] + dp[j][1];
//                     }else
//                     ndp[k][0] += dp[j][0] + dp[j][1] + dp[j][2];
//                 }
//                 ndp[k][0] %= mod;
//                 ndp[k][1] %= mod;
//                 ndp[k][2] %= mod;
//             }
//         }
//         dp = ndp;
//     }
//     auto qmi = [&](int a,int b)->int{
//         int res = 1ll;
//         while(b){
//             if(b & 0x1) res = res * a % mod;
//             b >>= 1;
//             a = a * a % mod;
//         }
//         return res;
//     };
//     int cnt = 0;
//     for(int i=1;i<=n;i++) cnt += s[i] == '?';
//     int ans = qmi(26,cnt);
//     // cerr << ans << endl;
//     for(int i=0;i<26;i++){
//         for(int j=0;j<3;j++){
//             ans = (ans - dp[i][j] + mod) % mod;
//         }
//     }
//     cout << ans << endl;
// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);
//     int T = 1;
//     cin >> T;
//     while(T --) solve();
//     return 0;
// }
