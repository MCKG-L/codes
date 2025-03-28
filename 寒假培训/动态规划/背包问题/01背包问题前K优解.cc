#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0xffffff
const int N = 5005, K = 55;
int w[N],v[N],temp[K];
int dp[N][K];// k表示第k优解[1....k]
int n,k,m;
int main()
{
    cin >> k >> m >> n;
    for(int i=1;i<=n;i++) cin >> w[i] >> v[i];
    for(int i=0;i<=m;i++){
        for(int c=1;c<=k;c++){
            dp[i][c] = -INF;
        }
    }
    dp[0][1] = 0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            int a=1,b=1,cnt=0;
            while(cnt <= k){
                if(dp[j][a] > dp[j-w[i]][b] + v[i]){
                    temp[++cnt] = dp[j][a++];
                }else{
                    temp[++cnt] = dp[j-w[i]][b++] + v[i];
                }
            }
            for(int c=1;c<=k;c++){
                dp[j][c] = temp[c];
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans += dp[m][i];
    }
    cout << ans;
    return 0;
}

