#include <iostream>
using namespace std;
typedef long long ll;
void solve(){
    ll a,s;
    cin >> a >> s;
    ll k = s - 2 * a;
    if(k < 0){
        cout << "No" << endl;
        return;
    }
    for(int i=60;i>=0;i--){
        int d = k >> i & 1;
        int da = a >> i & 1;
        if(da == 1 && d == 1){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}