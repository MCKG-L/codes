#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 10;
int mask[N];
int n;
void solve(){
    cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        while(x % 2 == 0) cnt ++,x /= 2;
    }
    // cout << cnt << "--" << endl;
    if(cnt >= n){
        cout << 0 << endl;
        return;
    }
    int d = n - cnt;
    int tmp[n+1];
    for(int i=1;i<=n;i++){
        tmp[i] = mask[i];
    }
    sort(tmp+1,tmp+n+1);
    int ans = 0;
    for(int i=n;i>=1;i--){
        d -= tmp[i];
        ans ++;
        if(d <= 0){
            cout << ans << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main()
{
    int t;cin >> t;
    for(int i=1;i<=(int)(2e5 + 1);i++){
        int x = i;
        while(x % 2 == 0) mask[i] ++,x /= 2;
    }
    // for(int i=1;i<=100;i++)
    //  cout << mask[i] << ' ';
    while(t--) solve();
    return 0;
}