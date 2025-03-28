#include <iostream>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
ll a[N];
void solve(){
    ll sum = 0;
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
        a[i] += a[i-1];
    }
    while(m--){
        ll l,r,k;
        cin >> l >> r >> k;
        ll len = a[r] - a[l-1];
        if((sum - len + k * (r-l+1)) & 1) puts("YES");
        else puts("NO");
    }

}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}