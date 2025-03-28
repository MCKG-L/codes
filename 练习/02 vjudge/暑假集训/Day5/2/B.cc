#include <iostream>
#include <cmath>
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    if(k > 31){
        cout << (n + 1) << endl;
    }else{
        long long ans = pow(2,k);
        ans = min(ans,(long long)(n + 1));
        cout << ans << endl;
    }
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}