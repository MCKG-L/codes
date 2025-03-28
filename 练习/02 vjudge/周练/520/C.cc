#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int n;
int a[N];
void solve(){
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    long long ans = 0;
    for(int i=0;i<n-1;i++){
        ans += max(a[i]-a[i+1],0);
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}