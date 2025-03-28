#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,inf = 1e18;

void solve(){
    int n,k;
    cin >> n >> k;
    int tot = 0;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        tot ^= a[i];
    }
    int ans = -1;
    auto dfs = [&](auto dfs,int u,int cnt,int t)->void{
        if(cnt > k || u > n + 1){
            return;
        }
        if(cnt == k){
            ans = max(ans,t);
            return;
        }
        if(cnt == n - k){
            ans = max(ans,tot ^ t);
            return;
        }
        dfs(dfs,u+1,cnt,t);
        dfs(dfs,u+1,cnt+1,t^a[u]);
    };
    dfs(dfs,1,0,0);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}