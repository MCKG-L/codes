#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n,k,a,b;
    cin >> n >> k >> a >> b;
    vector<PII> adj(n+1);
    for(int i=1;i<=n;i++){
        int x,y;cin >> x >> y;
        adj[i] = {x,y};
    }
    int d1 = 1e18,d2 = 1e18;
    auto [x,y] = adj[a];
    auto [x2,y2] = adj[b];
    for(int i=1;i<=k;i++){
        auto [xx,yy] = adj[i];
        d1 = min(d1,abs(x-xx)+abs(y-yy));
        d2 = min(d2,abs(x2-xx)+abs(y2-yy));
    }
    int ans = abs(x-x2) + abs(y-y2);
    ans = min(ans,d1+d2);
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