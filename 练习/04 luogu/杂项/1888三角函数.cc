#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    int max_n = max(a,max(b,c));
    int min_n = min(a,min(b,c));
    int gcd_n = __gcd(min_n,max_n);
    cout << min_n/gcd_n << '/' << max_n/gcd_n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}