#include <iostream>
#include <cmath>
using namespace std;
// int func(int n){
//     int cnt = 0;
//     while(n){
//         cnt ++;
//         n /= 10;
//     }
//     return cnt;
// }
void solve(){
    int l,r;
    cin >> l >> r;
    // int k1 = func(l);
    // int k2 = func(r);
    if(r - l > 100){
        int tmp = l;
        l /= 10;l /= 10;
        l *= 100;
        int ans = l + 90;
        if(ans < tmp) ans += 100;
        cout << ans << endl;
        return;
    }
    int ans = 0;
    int max_d = 0;
    for(int i=l;i<=r;i++){
        int k = i;
        int max_ = 0;
        int min_ = 9;
        // int max_d = 0;
        while(k){
            int p = k % 10;
            min_ = min(p,min_);
            max_ = max(max_,p);
            k /= 10;
        }
        // cout << "----";
        // cout << max_ << ' ' << min_ << endl;
        if(max_ - min_ >= max_d){
            max_d = max_ - min_;
            ans = i;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}