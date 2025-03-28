#include <iostream>
#include <cstring>
using namespace std;
/*
给出n个字符串和m次询问，每一次询问，给出一个字符串s和最大操作次数Max，问在Max次操作之内
能将a[i]变成s的字符串有多少个？

*/
const int N = 15,M = 1010;
int n,m;
int dp[N][N];
char str[M][N];
int func(char a[],char b[]){
    int la = strlen(a+1),lb = strlen(b+1);
    for(int i=0;i<=la;i++) dp[i][0] = i;
    for(int i=0;i<=lb;i++) dp[0][i] = i;
    for(int i=1;i<=la;i++){
        for(int j=1;j<=lb;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
            dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(a[i]!=b[j]));
        }
    }
    return dp[la][lb];
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> str[i] + 1;
    while(m--){
        char s[N];
        int Max;
        cin >> s + 1 >> Max;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(func(str[i],s) <= Max){
                ans ++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}