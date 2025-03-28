#include <iostream>
using namespace std;
typedef long long ll;
void solve(){
    ll a,b,n;
    cin >> a >> b >> n;
    ll t = 0,ans = b;
    if(a > b){
        t = a + b;
        ans += (n-1)/2*t + (n-1)%2*b;
        // if((n-1) % 2) ans += b;
    }else{
        ans = n * b;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}