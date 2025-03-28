#include <iostream>
#include <algorithm>
using namespace std;
const int N = 51;
int a[N];
int n;
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int ans = 0;
    for(int i=0;i<n/2;i++){
        ans += a[n-i-1]-a[i];
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}