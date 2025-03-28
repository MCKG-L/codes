#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll n,d;
    cin >> n >> d;
    ll t = n;
    ll k = 1;
    while(t) k *= 10,t /= 10;
    cout << ((123456789 * k * 10) + d * k + n - 1) / n << endl; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}