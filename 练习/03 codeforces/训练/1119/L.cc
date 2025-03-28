#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    int cnt = 0,ans = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        int x = a[i];
        while(x < a[i-1]) x *= 2,cnt ++;
        x = a[i-1];
        while(cnt && 2*x <= a[i]) cnt --,x *= 2;
        ans += cnt;
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