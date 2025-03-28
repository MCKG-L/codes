#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n),b(n);
    vector<PII> adj(n);
    int ans = 0;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++){
        if(a[i] < b[i]){
            adj[i] = {a[i],b[i]};
        }else{
            adj[i] = {b[i],a[i]};
        }
        ans += abs(a[i]-b[i]);
    }
    sort(adj.begin(),adj.end());
    int M = 0,m = 1e9;
    for(auto [l,r] : adj){
        M = max(M,2*(l-m));
        m = min(m,r);
    }
    cout << ans + M << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}