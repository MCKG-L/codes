#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
ll lcm(ll a,ll b){
    return a * b / __gcd(a,b);
}
int main()
{
    int n;cin >> n;
    ll sa=0,sb=1,d = 0;
    for(int i=0;i<n;i++){
        ll a,b;char c;
		cin >> a >> c >> b;
        ll lm = lcm(sb,b);
        sa = sa * lm / sb + a * lm / b;
        sb = lm;
        if(sa != 0){
            ll gcd = __gcd(sa,sb);
            sa /= gcd,sb /= gcd;
        }else sb = 1;
        
        d += sa / sb;
        sa %= sb;
    }
    if(d != 0 && sa != 0) cout << d << " " << sa << "/" << sb;
    else if(sa != 0) cout << sa << "/" << sb;
    else if(d != 0) cout << d;
    else cout << 0;
    return 0;
}