#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10,INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> a(n),c(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> c[i];
    int ans = INF;
    for(int j=1;j<n-1;j++){
        int x = a[j];
        int sum1 = INF;
        for(int i=0;i<j;i++){
            if(a[i] < x){
                sum1 = min(sum1,c[i]);
            }
        }
        int sum2 = INF;
        for(int k=j+1;k<n;k++){
            if(a[k] > x){
                sum2 = min(sum2,c[k]);
            }
        }
        ans = min(ans,sum1+sum2+c[j]);
    }
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}