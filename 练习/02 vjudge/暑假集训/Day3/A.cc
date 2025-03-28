#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n;
int a[N];
void solve(){
    cin >> n;
    int cnt = 0,s = 0;
    ll ans = 0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        if(a[i] < 0) ans += -a[i],s = 1;
        else if(a[i] > 0){
            ans += a[i];
            cnt += s;
            s = 0;
        }
    }
    cnt += s;
    cout << ans << ' ' << cnt << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}