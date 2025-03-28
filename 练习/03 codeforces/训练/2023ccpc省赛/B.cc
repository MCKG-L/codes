#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> lmax(n+1),rmin(n+1);
    lmax[0] = a[0],rmin[n-1] = a[n-1];
    for(int i=1;i<n;i++){
        lmax[i] = max(lmax[i-1],a[i]);
    }
    for(int i=n-2;i>=0;i--){
        rmin[i] = min(rmin[i+1],a[i]);
    }
    int ans = 0;
    for(int k=1;k<=n;k++){
        bool ok = 1;
        for(int i=k;i<n;i+=k){
            if(!(lmax[i-1] <= rmin[i])){
                ok = 0;break;
            }
        }
        if(ok) ans ++;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}