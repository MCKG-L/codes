#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n,M;cin >> n >> M;
    int ans = -1;
    int l = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        ans = max(x-l,ans);
        l = x;
    }
    ans = max(ans,2*(M-l));
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