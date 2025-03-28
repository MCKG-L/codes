#include <iostream>
#include <cmath>
#define int long long
using namespace std;
void solve(){
    int a,b;
    cin >> a >> b;
    int d = abs(a-b);
    int ans = 0;
    if(a > b){
        if(d & 1){
            ans = 2;
        }else{
            ans = 1;
        }
    }else if(a < b){
        if(d & 1) ans = 1;
        else if((d / 2) & 1) ans = 2;
        else ans = 3;
    }
    else{
        ans = 0;
    }
    cout << ans << endl;
}
signed main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}