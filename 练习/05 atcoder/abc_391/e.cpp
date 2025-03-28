#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = ' ' + s;
    vector<string> A(n+1);//操作i次之后的结果
    A[0] = s;
    for(int i=1;i<=n;i++){
        int len = A[i-1].size() - 1;
        string res = " ";int cnt = 0;
        // string S = A[i-1];
        for(int j=1;j<=len/3;j++){
            cnt = 0;
            cnt += (A[i-1][3*j-2] == '1');
            cnt += (A[i-1][3*j-1] == '1');
            cnt += (A[i-1][3*j] == '1');
            if(cnt > 1){
                res += "1";
            }else{
                res += "0";
            }
        }
        A[i] = res;
    }
    // for(int i=0;i<=n;i++) cout << A[i] << endl;

    // cout << endl;
    int m = pow(3,n),inf = 1e9;
    //DP
    vector<vector<int>> dp(n+1,vector<int>(m+1,inf));
    //经经过操作i次之后的字符串中的第j个位置元素反转需要的最小次数
    for(int i=1;i<=m;i++) dp[0][i] = 1;//源字符串反转（不进行操作）
    for(int i=1;i<=n;i++){
        int len = A[i].size() - 1;
        for(int j=1;j<=len;j++){
            //转移方程
            //A[i][j]依赖于A[i-1][3*j-2]、A[i-1][3*j-1]、A[i-1][3*j]
            //计算和A[i][j]相同的个数
            int cnt = 0;
            cnt += (A[i-1][3*j-2] == A[i][j]);
            cnt += (A[i-1][3*j-1] == A[i][j]);
            cnt += (A[i-1][3*j]   == A[i][j]);
            if(cnt == 2){
                if(A[i-1][3*j-2] != A[i][j]){
                    dp[i][j] = min(dp[i-1][3*j-1],dp[i-1][3*j]);
                }else if(A[i-1][3*j-1] != A[i][j]){
                    dp[i][j] = min(dp[i-1][3*j-2],dp[i-1][3*j]);
                }else{
                    dp[i][j] = min(dp[i-1][3*j-2],dp[i-1][3*j-1]);
                }
            }else{ //cnt == 3
                dp[i][j] = min(dp[i][j],dp[i-1][3*j-2]+dp[i-1][3*j-1]);
                dp[i][j] = min(dp[i][j],dp[i-1][3*j-2]+dp[i-1][3*j]);
                dp[i][j] = min(dp[i][j],dp[i-1][3*j-1]+dp[i-1][3*j]);
            }
        }
    }
    cout << dp[n][1] << endl;
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