#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
typedef pair<int,int> PII;
void solve(){
    ll a,b,n;
    cin >> a >> b >> n;
    ll d = n / (5 * a + 2 * b),r = n % (5 * a + 2 * b);
    ll ans = 7 * d;
    if(r <= 5 * a){
        ans += (r + a - 1) / a;
    }else{
        ans += 5;
        ans += (r - 5 * a + b - 1) / b;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}