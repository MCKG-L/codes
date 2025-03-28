#include <bits/stdc++.h>
using namespace std;
/*
给定两个字符串str1,str2
str1: "a12bc345def"
str2: "mnp123qrs45z"

最长公共子序列和为："12345" 返回5
*/
//样本对应模型
/* 尝试模型
1、从左到右尝试模型
2、范围尝试模型
3、样本对应模型
*/
string s1,s2;
int dp(){
    //尝试
    int N = s1.size();
    int M = s2.size();
    int dp[N][M];

    //base-case
    dp[0][0] = s1[0] == s2[0] ? 1 : 0;
    for(int i=1;i<N;i++){
        dp[i][0] = s1[i] == s2[0] ? 1 : dp[i-1][0];
    }
    for(int j=1;j<M;j++){
        dp[0][j] = s1[0] == s2[j] ? 1 : dp[0][j-1];
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<M;j++){
            int p1 = dp[i-1][j];
            int p2 = dp[i][j-1];
            int p3 = s1[i] == s2[j] ? (1 + dp[i-1][j-1]) : 0;
            dp[i][j] = max(max(p1,p2),p3);
        }
    }
    cout << "dp: \n";
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%2d ",dp[i][j]);
        }
        cout << endl;
    }
    return dp[N-1][M-1];
}

int main()
{
    cin >> s1 >> s2;
    cout << dp();
    return 0;
}