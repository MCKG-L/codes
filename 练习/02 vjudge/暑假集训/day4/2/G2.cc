#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int v[N],a[N],sum[N];
int n,c;
void solve(){
    cin >> n >> c;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        a[i] = x;
        v[i] = min(x+i,x+n+1-i);
    }
    sort(v+1,v+1+n);
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1] + v[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i] + i > c) continue;
        int p = min(a[i]+i,a[i]+n+1-i);
        int k = upper_bound(sum+1,sum+1+n,c-(a[i]+i))-(sum+1);
        if(v[k] >= p){
            k = upper_bound(sum+1,sum+1+n,c+p-(a[i]+i))-(sum+1);
            ans = max(ans,k);
        }else ans = max(ans,k+1);
    }
    cout << ans << endl;
}
signed main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}