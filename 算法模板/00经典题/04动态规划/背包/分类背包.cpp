#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 5010;
/*
题目来源：abc_390_e
给定n个食物，每个食物都包含一种数量维生素和一定的热量，维生素只有三种
求怎么选择食物，能在摄入不超过m热量的情况下，使得摄入的三种维生素的最小值最大

每次只考虑一种维生素，则可以将食物分为三类，根据贪心法可知：对于维生素k，选择的食物一定只含有维生素k
所以可以分别求出在满足热量摄入比超过j的情况下摄入的维生素k的最大值(01背包问题)
最后考虑将m的热量分配给三种维生素的食物(N^2枚举)
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> dp1(m+1,0),dp2(m+1,0),dp3(m+1,0);
    vector<int> a(n+1),b(n+1),c(n+1);
    for(int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
    auto dp = [&](vector<int> &dp,int k){
        for(int i=1;i<=n;i++){
            for(int j=m;j>=c[i];j--){
                if(a[i] != k) continue;
                dp[j] = max(dp[j],dp[j-c[i]]+b[i]);
            }
        }
    };
    dp(dp1,1),dp(dp2,2),dp(dp3,3);
    // cout << dp1[m] << ' ' << dp2[m] << ' ' << dp3[m] << endl;
    int ans = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j+i<=m;j++){
            ans = max(ans,min({dp1[i],dp2[j],dp3[m-i-j]}));
        }
    }
    cout << ans << endl;
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