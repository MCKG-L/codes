#include <iostream>
using namespace std;
typedef long long ll;
ll qmi(ll a,ll b,ll p){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
int main()
{
    ll a,b,p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << qmi(a,b,p);
    return 0;
}