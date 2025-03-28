#include <bits/stdc++.h>
using namespace std;
/*
求最大子段和是典型的动态规划问题，dp[i]表示以a[i]结尾时的最大子段和
递推表达式：dp[i] = max(a[i],dp[i-1]+a[i]);
*/
int main()
{
    int n,ans=-1e5;
    cin >> n;
    vector<int> a(n),dp(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    dp[0] = a[0];
    ans = dp[0];
    for(int i=1;i<n;i++){
        dp[i] = max(a[i],dp[i-1]+a[i]);
        ans = max(ans,dp[i]);
    }
    cout << ans;

}