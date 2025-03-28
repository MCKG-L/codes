#include <iostream>
#include <cmath>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
int func(int x){
    int cnt = 0;
    while(x){
        cnt ++;
        x /= 10;
    }
    return cnt;
}
void solve(){
    int x;cin >> x;
    int k = func(x);
    int ans = 0;
    for(int i=1;i<k;i++){
        ans += 9 * (int)pow(10,i-1) * i;
    }
    ans += (x-(int)pow(10,k-1)+1)*k;
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
