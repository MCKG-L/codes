#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N],d[N];
int n,k;
void solve(){
    cin >> n >> k;
    int ans = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++) d[i] = abs(a[i+1] - a[i]),ans += d[i];
    sort(d+1,d+n);
    for(int i=n-1;i>=n+1-k;i--) ans -= d[i];
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}