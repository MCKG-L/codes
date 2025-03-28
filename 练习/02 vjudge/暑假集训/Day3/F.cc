#include <iostream>
#include <vector>
#define endl '\n'
#define int long long
using namespace std;
//树上dp 
const int N = 2e5 + 10;
int dp1[N],dp2[N];
int max_n[N],min_n[N];
int n,idx;
void solve(){
    idx = 1;max_n[1] = 1;dp2[1] = 1;
    cin >> n;
    for(int i=0;i<n;i++){
        char c;cin >> c;
        if(c == '+'){
            int u,x;
            cin >> u >> x;
            max_n[++idx] = max(max_n[u]+x,x);
            min_n[idx] = min(min_n[u]+x,x);
            dp1[idx] = min(min_n[idx],dp1[u]);
            dp2[idx] = max(max_n[idx],dp2[u]);
        }else{
            int u,v,k;
            cin >> u >> v >> k;//u为1
            if(dp1[v] <= k && dp2[v] >= k) puts("YES");
            else puts("NO");
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}