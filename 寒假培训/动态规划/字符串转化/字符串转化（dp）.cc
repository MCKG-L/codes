#include <bits/stdc++.h>
using namespace std;
/*
    字符串转化
    有26种对应关系 1->A 2->B 3->C ..... 11->K ... 26->Z
    给定一个数字字符串如"111",可以转化为"AAA" "KA" "AK"；
    给定一个数字字符串（0~9组成），问有多少种转化结果？

*/
string s;
int dp[100];
int solve(){
    int n = s.size();
    dp[n] = 1;
    for(int i=n-1;i>=0;i--){
        int ans = 0;
        if(s[i] == '0') ans = 0;
        else{
            ans = dp[i+1];//单转
            if((s[i]-'0')*10+(s[i+1]-'0') < 27 && i+1 < n){
                ans += dp[i+2];
            }//判断是否可以和下一个字符组合转
        }
        dp[i] = ans;
    }
    return dp[0];
}
int main()
{
    cin >> s;
    cout << solve() << endl;
    cout << "dp: " << endl;
    int n = s.size();
    for(int i=0;i<=n;i++){
        cout << dp[i] << " ";
    }
    return 0;
}