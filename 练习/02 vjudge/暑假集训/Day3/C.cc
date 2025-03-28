#include <iostream>
using namespace std;
typedef long long ll;
void solve(){
    ll n,ans = 0;
    cin >> n;
    ans = n;
    while(1){
        if(n == 1) break;
        ans += n / 2;
        n /= 2;
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}