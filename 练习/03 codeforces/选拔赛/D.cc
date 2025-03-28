#include <iostream>
#define endl '\n'
using namespace std;
typedef long long ll;
int a[3],b[3];
void solve(){
    ll ans = 0;
    for(int i=0;i<3;i++) cin >> a[i];
    for(int i=0;i<3;i++) cin >> b[i];
    //后手赢
    for(int i=0;i<3;i++){
        int p = (i + 1) % 3;
        int t = min(a[i],b[p]);
        ans += t;
        a[i] -= t,b[p] -= t;
    }
    //平局
    for(int i=0;i<3;i++){
        int t = min(a[i],b[i]);
        a[i] -= t,b[i] -= t;
    }
    //后手输
    for(int i=0;i<3;i++){
        int p = (i + 1) % 3;
        int t = min(a[p],b[i]);
        ans -= t;
        a[p] -= t,b[i] -= t;
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}