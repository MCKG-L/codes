#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    for(int i=a+1;i<=c;i++){
        int gcd = __gcd(a*b,i);
        int y = a * b / gcd;
        y = d / y * y;
        if(y > b && y <= d){
            cout << i << ' ' << y << endl;
            return;
        }
        // int f = a * b / gcd;
        // if(b/f < d/f){ //k 存在
        //     int y = d/f*f;
        //     cout << i << ' ' << y << endl;
        //     return;
        // }
    }
    cout << -1 << ' ' << -1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}