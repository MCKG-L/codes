#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int f[N],n;
int a[N];
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    f[n+1] = 0;
    for(int i=n;i>=1;i--){
        f[i] = f[i+1] + 1;
        int p = i + a[i];
        if(p <= n) f[i] = min(f[i],f[p+1]);
    }
    cout << f[1] << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}