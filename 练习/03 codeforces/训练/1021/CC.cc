#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10,INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    int l = 0,r = INF;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=2;i<=n;i++){
        int ll = 0,rr = INF;
        if(a[i] > a[i-1]){
            rr = (a[i] + a[i-1]) / 2;
            ll = -INF;
        }else if(a[i] < a[i-1]){
            ll = (a[i] + a[i-1] + 1) / 2;
            rr = INF;
        }
        l = max(l,ll),r = min(r,rr);
    }
    if(l > r) cout << -1 << endl;
    else cout << l << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}