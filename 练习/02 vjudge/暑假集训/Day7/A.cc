#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 110,INF = 1e9;
int f[N][N];
int n,k;
int a[N];
void solve(){
    memset(f,0x3f,sizeof f);
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    f[1][1] = 0;
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