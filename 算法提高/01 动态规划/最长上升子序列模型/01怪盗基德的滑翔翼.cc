#include <iostream>
using namespace std;
const int N = 110;
int n;
int a[N],b[N];
int f[N],dp[N];
void solve(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[n-i+1] = a[i];
    }
    //正向
    for(int i=1;i<=n;i++){
        f[i] = 1;
        for(int j=1;j<i;j++){
            if(a[j] < a[i]) f[i] = max(f[i],f[j]+1);
        }
    }
    //反向
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(b[j] < b[i]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans,f[i]),ans = max(ans,dp[i]);
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}