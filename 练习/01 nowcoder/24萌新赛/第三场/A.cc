#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 3e5 + 10;
using ll = long long;
vector<vector<int>> a(N);
int x,y,n;
void solve(){
    cin >> n >> x >> y;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> cnt(n + 1);
    vector<bool> path(n + 1);
    function<int(int,int)> dfs = [&](int u,int fa)->int{
        cnt[u] = 1;
        if(u == x) path[u] = 1;
        for(auto v : a[u]){
            if(v == fa) continue;
            cnt[u] += dfs(v,u);
            path[u] = path[u] | path[v];
        }
        return cnt[u];
    };
    dfs(y,0);
    for(auto v : a[y]){
        if(path[v]) cnt[y] -= cnt[v];
    }
    cout << 1LL * cnt[x] * cnt[y] << endl;
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