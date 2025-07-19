#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e6 + 10,mod = 998244353,inf = 1e18;

int n,m1,m2;
int p[N];
int find(int x){
    while(p[x] != x) x = p[x] = p[p[x]];
    return x;
}
void init(){
    for(int i=1;i<=n;i++) p[i] = i;
}
void solve(){
    cin >> n >> m1 >> m2;
    init();
    for(int i=1;i<=m1;i++){
        int u,v;
        cin >> u >> v;
        int a = find(u),b = find(v);
        p[a] = b;
    }
    vector<int> cnt(n + 1);
    vector<vector<int>> a(n + 1);
    vector<int> vis(n + 1,1);
    for(int i=1;i<=m2;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        vis[u] = vis[v] = 0;
    }
    int ans = 0;
    auto dfs = [&](auto dfs,int u,int fa)->void{
        vis[u] = 1;
        ans += cnt[find(u)] ++;
        for(auto v : a[u]){
            if(v == fa || vis[v]) continue;
            dfs(dfs,v,u);
        }
        if(u == fa) cnt[find(u)] = 0;
    };
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        dfs(dfs,i,i);
    }
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