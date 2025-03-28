#include <bits/stdc++.h>
using namespace std;
int st[205],p[50];
int cnt = 1;
void getp(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]){
            p[cnt++] = i;
            for(int j=i+i;j<=n;j+=i){
                st[j] = 1;
            }
        }
    }
}
int dp[201];
void solve(int n){
    getp(200);
    dp[0] = 1;
    dp[1] = 0;
    for(int i=1;i<cnt;i++){
        for(int j=p[i];j<=n;j++){
            dp[j] += dp[j-p[i]];
        }
    }
}
int main()
{
    int n;
    solve(200);
    while(cin >> n){
        cout << dp[n] << endl;
    }
    return 0;
}