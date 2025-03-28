#include <iostream>
#define int long long
using namespace std;
const int N = 2010;
int ans[(int)(1e7 + 10)];
int a[N][N];
void solve(){
    int n;cin >> n;
    cout << ans[n] << endl;
}
signed main()
{
    int t;cin >> t;
    int k = 1;
    for(int i=1;i<N;i++){
        for(int j=1;j<=i;j++){
            a[i-j+1][j] = a[i-j][j] + a[i-j+1][j-1] - a[i-j][j-1] + k * k;
            ans[k] = a[i-j+1][j];
            k ++;
        }
    }
    while(t--) solve();
    return 0;
}