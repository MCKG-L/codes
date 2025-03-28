#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N],n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int ans = 0,k = a[0];
    for(int i=0;i<n;i++){
        k = k & a[i];
        if(k == 0){
            ans ++;
            k = a[i+1];
        }
    }
    if(ans == 0) ans = 1;
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}