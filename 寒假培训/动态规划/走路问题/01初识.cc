#include <bits/stdc++.h>
using namespace std;
/*
从暴力递归到动态规划！
*/
//1、求斐波那契数列
//暴力递归
int find(int n){
    if(n <= 2) return 1;
    return find(n-1) + find(n-2);
}
//动态规划 在递归的过程中有重复子问题
const int N = 102;
int dp[N];
void m_find(int n){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
}
int main()
{
    int n;cin >> n;
    // cout << find(n);
    m_find(100);
    while(cin >> n) cout << dp[n] << " ";
    return 0;
}