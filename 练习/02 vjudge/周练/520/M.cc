#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll a,b,c,d;
void solve(){
    cin >> a >> b >> c >> d;
    if(a <= b){
        cout << b << endl;
    }else{
        if(c <= d){
            cout << -1 << endl;
        }else{
            cout << (ll)(b + ceil(1.0*(a-b)/(c-d))*c) << endl;
        }
    }
}

int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}