#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
int a,b,c,n,w;
void solve(){
    cin >> a >> b >> c >> n >> w;
    if(b < c) swap(b,c);
    int ans = 1e18;
    for(int x=0;x<=n;x++){
        int l = 0,r = n-x;
        int mx = -1e18;
        while(l <= r){
            int mid = l + r >> 1;
            if(a*x+mid*b+(n-x-mid)*c-w <= 0){
                mx = max(mx,a*x+mid*b+(n-x-mid)*c);l = mid + 1;
            }else r = mid - 1;
        }
        ans = min(ans,w-mx);
        l = 0,r = n-x;
        int mn = 1e18;
        while(l <= r){
            int mid = l + r >> 1;
            if(a*x+mid*b+(n-x-mid)*c-w >= 0){
                mn = min(mn,a*x+mid*b+(n-x-mid)*c);r = mid - 1;
            }else l = mid + 1;
        }
        ans = min(ans,mn-w);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}