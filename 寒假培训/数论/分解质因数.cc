#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll cnt;
void devide(ll n){
    for(ll i=2;i<=n/i;i++){
        if(n % i == 0){
            ll cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            cout << cnt << ":" << i << endl;
        }
    }
    if(n > 1) cout << 1 << ":" << n << endl;
}
int main()
{
    ll n;
    cin >> n;
    devide(n);
    // cout << cnt;
    return 0;
}