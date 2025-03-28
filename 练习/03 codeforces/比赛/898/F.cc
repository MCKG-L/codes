#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int f[N],sum[N];
int a[N],h[N],s[N];
int n,k;
void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> h[i];
    h[0] = 1;s[0] = 1;
    for(int i=1;i<=n;i++){
        if(h[i-1] % h[i] == 0){
            if(sum[i-1] + a[i] > k){
                int p = s[i-1],ss = sum[i-1] + a[i];
                while(p <= i && ss - a[p] > k) ss -= a[p],p ++;
                if(p == i){
                    if(a[i] <= k){
                        f[i] = 1;s[i] = i;
                        sum[i] = a[i];
                    }else{
                        f[i] = 0;s[i] = i + 1;
                        sum[i] = 0;
                    }
                }else{
                    f[i] = i - p;
                    s[i] = p + 1;
                    sum[i] = ss - a[p];
                }
            }else{
                f[i] = f[i-1] + 1;
                sum[i] = sum[i-1] + a[i];
                s[i] = s[i-1];
            }
        }else{
            if(a[i] <= k){
                f[i] = 1;s[i] = i;
                sum[i] = a[i];
            }else{
                f[i] = 0;s[i] = i + 1;
                sum[i] = 0;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << sum[i] << ' ';
    // }
    // cout << endl;
    // for(int i=1;i<=n;i++){
    //     cout << s[i] <<  ' ';
    // }
    // cout << endl;
    // for(int i=1;i<=n;i++) cout << f[i] << ' ';
    // cout << endl;
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans,f[i]);
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}