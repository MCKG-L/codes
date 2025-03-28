#include <iostream>
using namespace std;
//转化为二维前缀和
typedef long long ll;
const int N = 2010;//取两倍大小
ll a[N][N];
ll ans[(int)(1e7 + 10)];
void solve(){
    int n;cin >> n;
    cout << ans[n] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //预处理
    ll k = 1;
    for(int i=1;i<N;i++){
        for(int j=i-1;j>=1;j--){
            a[j][i-j] = a[j-1][i-j] + a[j][i-j-1] - a[j-1][i-j-1] + k*k;
            ans[k] = a[j][i-j];
            k ++;
        }
    }
    int t;cin >> t;
    while(t--) solve();
    return 0;
}