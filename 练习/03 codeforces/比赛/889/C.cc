#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n+1),pre(n+2);
    pre[n+1] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=n;i>=1;i--){
        pre[i] = pre[i+1];
        if(a[i] >= 0) pre[i] += a[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int t = pre[i+1];
        if(i & 1) t += a[i];
        ans = max(ans,t);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}