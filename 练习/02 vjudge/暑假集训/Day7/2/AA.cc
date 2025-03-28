#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int f[N][N];
int a[N],n,k;
void solve(){
    cin >> n >> k;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=k;i++) f[1][i] = 0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            f[i][j] = f[i-1][j-1];
            f[i][j] = min(f[i][j],f[i-1][j]+abs(a[i]-a[i-1]));
        }
    }
    cout << f[n][k] << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}