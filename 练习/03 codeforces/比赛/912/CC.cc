#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void  solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans = 0,sum = 0;
    for(int i=n;i>=1;i--){
        sum += a[i];
        if(i == 1 || sum >= 0) ans += sum;
    }
    cout << ans << endl;
}
signed main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}