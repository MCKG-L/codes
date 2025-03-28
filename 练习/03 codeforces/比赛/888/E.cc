#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int c[N],cost[N],n,k;
map<int,int> mp;
vector<int> e[N];
int dfs(int u){
    if(cost[u] != -1) return cost[u];
    int ans = 0;
    for(auto i : e[u]) ans += dfs(i);
    if(e[u].size() == 0) ans = c[u];
    cost[u] = min(ans,c[u]);
    return cost[u];
}
void solve(){
    cin >> n >> k;mp.clear();
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<=n;i++) cin >> c[i],cost[i] = -1;
    for(int i=0;i<k;i++){
        int x;cin >> x;
        mp[x] ++;cost[x] = 0;
    }
    for(int i=1;i<=n;i++){
        int m;cin >> m;
        while(m--){
            int x;cin >> x;
            e[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++) dfs(i);
    for(int i=1;i<=n;i++) cout << cost[i] << ' ';
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}