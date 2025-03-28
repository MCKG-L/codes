#include <iostream>
#include <cmath>
using namespace std;
const int N = 55;
int h[N];
int n,m,k,H;
void solve(){
    cin >> n >> m >> k >> H;
    int ans = 0;
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++){
        int dh = abs(H-h[i]);
        if(dh && dh % k) continue;
        int dx = dh / k;
        if(dx >= 1 && dx <= m-1) ans ++;
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}