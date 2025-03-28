#include <iostream>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n;
void solve(){
    cin >> n;
    ll ans = 0,cnt = 0,s = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x < 0){
            ans += -x;s = 1;
        }else if(x > 0){
            ans += x;
            cnt += s;
            s = 0;
        }
    }
    cnt += s;
    cout << ans << ' ' << cnt << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}