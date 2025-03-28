#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n,k,q;
void solve(){
    cin >> n >> k >> q;
    int s = 0,ans = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x <= q) s ++;
        else{
            if(s >= k) ans += (s-k+2)*(s-k+1)/2;
            s = 0;
        }
    }
    if(s >= k) ans += (s-k+2)*(s-k+1)/2;
    cout << ans << endl;

}
signed main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}