#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int a[32][N];
bool k[32][N];
int n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        for(int j=0;j<32;j++){
            bool dx = (x >> j) & 1;
            k[j][i] = dx;
        }
    }
    int ans = 0;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<32;j++){
    //         cout << k[j][i];
    //     }
    //     cout << endl;
    // }
    for(int i=0;i<32;i++){
        int s = 0,cnt = 0;
        for(int j=1;j<=n;j++){
            if(k[i][j] == 1) s ++;
            else{
                cnt += s * (s + 1) / 2;
                s = 0;
            }
        }
        if(s > 0) cnt += s * (s + 1) / 2;
        // cout << cnt << "--\n";
        ans += cnt * (1ll << i);
    }
    cout << ans << endl;
}
signed main()
{
    int t = 1;
    cin >> t;
    while(t--) solve();
}