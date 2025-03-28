#include <iostream>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int cnt[N],a[N];
void solve(){
    int n,k,q;
    cin >> n >> k >> q;
    int s = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        int x = a[i];
        if(x <= q){
            s ++;
        }else{
            s = 0;
        }
        if(s >= k){
            cnt[i] = s-k+1;
        }else{
            cnt[i] = 0;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans += cnt[i];
    cout << ans << endl;
}
signed main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}