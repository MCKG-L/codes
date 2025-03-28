#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

vector<int> g[N];
void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> in(n+1),out(n+1);
    int k = 0;
    function<void(int,int)> dfs = [&](int u,int p) -> void {
        in[u] = k ++;
        for(auto v : g[u]){
            if(v == p) continue;
            dfs(v,u);
        }
        out[u] = k;
    };
    dfs(1,-1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<array<int,2>> ans(q);
    vector<vector<array<int,3> > > query(n+1);

}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}