#include <bits/stdc++.h>
using namespace std;
/*
求str的最长回文子序列可以转化为求 str和逆str的最长公共子序列

现用另外一种思路做 范围尝试模型--> 普遍情况要讨论两端要还是不要
*/
string s;
int dp(){
    int N = s.size();
    int dp[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = 0;
        }
    }
    dp[N-1][N-1] = 1;
    for(int i=0;i<N-1;i++){
        dp[i][i] = 1;
        dp[i][i+1] = s[i] == s[i+1] ? 2 : 1;
    }
    for(int l=N-3;l>=0;l--){
        for(int r=l+2;r<N;r++){
            // int p1 = dp[l+1][r-1];
            // int p2 = dp[l+1][r];
            // int p3 = dp[l][r-1];
            // int p4 = s[l] == s[r] ? (2 + dp[l+1][r-1]) : 0;
            // dp[l][r] = max(max(p1,p2),max(p3,p4));
            //根据严格依赖关系，发现最大只能出在p2或p3或p4,不可能出自p1,因为p2,p3,p4都不小于p1
            dp[l][r] = max(dp[l+1][r],dp[l][r-1]);
            if(s[l] == s[r]){
                dp[l][r] = max(dp[l][r],2+dp[l+1][r-1]);
            }
        }
    }
    cout << "dp: \n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%2d ",dp[i][j]);
        }
        cout << endl;
    }
    cout << "ans: ";
    return dp[0][N-1];
}
int main()
{
    cin >> s;
    cout << dp();
    return 0;
}