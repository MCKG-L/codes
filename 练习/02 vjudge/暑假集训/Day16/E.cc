#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
vector<vector<int>> e(N,vector<int>());
map<int,int> p;
int c[N],ans[N];
int n,k;
int dfs(int u){
    if(ans[u] != -1) return ans[u];
    int res = 0;
    int l = e[u].size();
    if(l == 0) res = c[u];
    for(int i=0;i<l;i++){
        if(p.count(e[u][i])) continue;
        res += dfs(e[u][i]);
    }
    ans[u] = min(c[u],res);
    if(p.count(u)) ans[u] = 0;
    return ans[u];
}
void solve(){
    cin >> n >> k;
    p.clear();
    for(int i=0;i<=n;i++){
        e[i].clear();
        c[i] = ans[i] = 0;
        ans[i] = -1;
    }
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<=k;i++){
        int x;cin >> x;
        p[x] ++;
    }
    for(int i=1;i<=n;i++){
        int m;cin >> m;
        if(m == 0) continue;
        while(m--){
            int x;cin >> x;
            e[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++) dfs(i);
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}