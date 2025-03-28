#include <iostream>
#define int long long
#define endl '\n'
using namespace std;
const int N = 31;
int a[N],n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = 0;
    if(n > 1 && a[n-1] == 0){
        cout << -1 << endl;
        return;
    }
    for(int i=n-2;i>=0;i--){
        if(a[i] == 0 && i != 0){
            cout << -1 << endl;
            return;
        }
        while(a[i] >= a[i+1]){
            a[i] /= 2;
            ans ++;
            if(a[i] == 0){
                if(i == 0) break;
                else{
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}