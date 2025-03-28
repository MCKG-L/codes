#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
/*
题目来源：abc_391_e
给定一个长度为3^n的01串，下面对这个01串执行n此以下操作：
将这个01串从左到右每3个一组，分为3^(n-1)组,将每一组整体变换为0或1(取决于小组中0和1的数量,取大者)
一次变换之后，得到新的长度为3^(n-1)的01串;
经过n此操作之后，这个01串变为长度为1的串，其值为0或1

现可以修改原01串的某些位置(0->1,1->0)，问最少需要修改多少位置，才可以使得原问题最终得到的串翻转(0->1,1->0)
定义dp[i][j]为将操作i次之后得到的字符串的第j个位置翻转，需要对原01串修改的最少位置数目
则最终问题答案即为dp[n][1]

记操作i次之后得到的01串为A[i],则A[i][j]的值严格依赖于A[i-1][3*j-2]、A[i-1][3*j-1]、A[i-1][3*j]
状态转移方程：
设依赖项为p1,p2,p3，则三者中与A[i][j]相同的至少有两个，下面分类讨论：
1、如果cnt=2，则翻转其中任意一个都可以使A[i][j]翻转，不失一般性，假设p1 = p2 = A[i][j]
则dp[i][j] = min(dp[i-1][3*j-2],dp[i-1][3*j-1])
2、如果cnt=3,则修改其中任意两个都可以使A[i][j]翻转，三种情况求Min
dp[i][j] = min(dp[i][j],dp[i-1][3*j-2]+dp[i-1][3*j-1]);
dp[i][j] = min(dp[i][j],dp[i-1][3*j-2]+dp[i-1][3*j]);
dp[i][j] = min(dp[i][j],dp[i-1][3*j-1]+dp[i-1][3*j]);
*/
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