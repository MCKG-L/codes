#include <iostream>
using namespace std;
using ll = long long;
ll qmi(int a,int b,int k){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % k;
        b >>= 1;
        a = (ll)a * a % k;
    }
    return ans;
}
int main()
{
    int a,b,k;//求a^b%k
    cin >> a >> b >> k;
    ll ans = qmi(a,b,k);
    cout << a << "^" << b << " mod " << k << "=" << ans;
    return 0;
}