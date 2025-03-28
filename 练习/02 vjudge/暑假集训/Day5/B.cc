#include <iostream>
#include <cmath>
using namespace std;
void solve(){
    long long n,k;
    cin >> n >> k;
    if(k > 31){
        cout << n + 1 << endl;
    }
    else{
        long long ans = pow(2,k);
        ans = min(ans,n + 1);
        cout << ans << endl;
    }
}
int main()
{
    int t;cin >> t;
    int k = 1 << 2;
    while(t--) solve();
    return 0;
}