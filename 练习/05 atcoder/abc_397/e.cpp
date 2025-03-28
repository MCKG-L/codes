#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 3e18;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> a(n*k+1);
    vector<int> sz(n*k+1,0);
    for(int i=0;i<n*k-1;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    auto dfs = [&](auto dfs,int u,int fa)->bool{
        int cnt = 0,now = 0;
        for(auto v : a[u]){
            if(v == fa) continue;
            if(!dfs(dfs,v,u)) return false;
            if(sz[v] == 0) continue;
            now += sz[v];cnt ++;
        }
        if(cnt >= 3 || (cnt == 2 && now + 1 != k)) return false;
        sz[u] = now + 1 == k ? 0 : now + 1;
        return true;
    };
    cout << (dfs(dfs,1,0) ? "Yes" : "No") << endl;
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