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
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans = 0;
    if(a[1] == 0) ans ++;
    for(int i=2;i<=n;i++){
        if(a[i] == 0) ans ++;
        else if(a[i] == 1 && a[i-1] == 1) ans ++,a[i] = 0;
        else if(a[i] == 2 && a[i-1] == 2) ans ++,a[i] = 0;
        else{
            if(a[i-1] == 1) a[i] = 2;
            else if(a[i-1] == 2) a[i] = 1;
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}