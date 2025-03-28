#include <iostream>
using namespace std;

/*
有多组物品，每一组中的物品只能选其中一个，在背包容量有限的情况下，装出价值和最多的物品

*/
const int N = 110;
int n,m;
int v[N][N],w[N][N],s[N];
int dp[N];
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        for(int j=0;j<s[i];j++){
            cin >> v[i][j] >> w[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<s[i];k++){
                if(v[i][k] <= j){
                    dp[j] = max(dp[j],dp[j-v[i][k]]+w[i][k]);
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}