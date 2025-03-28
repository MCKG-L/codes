#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
typedef pair<int,int> PII;
const long long INF = 1e18;
void solve(){
    int n,m;cin >> n >> m;
    vector<PII> a[n+1];
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    vector<int> s(n+1);
    for(int i=1;i<=n;i++) cin >> s[i];
    vector<vector<int>> st(n+1,vector<int>(1001,false));
    vector<vector<int>> dis(n+1,vector<int>(1001,INF));
    dis[1][s[1]] = 0;
    priority_queue<array<int,3>> heap;
    heap.push({0,1,s[1]});
    while(heap.size()){
        auto [d,u,k] = heap.top();
        heap.pop();
        if(st[u][k] || dis[u][k] == INF) continue;
        st[u][k] = true;
        for(auto [v,w] : a[u]){
            int c = min(k,s[v]);
            if(dis[v][c] > dis[u][k] + 1LL * w * k){
                dis[v][c] = dis[u][k] + 1LL * w * k;
                heap.push({-dis[v][c],v,c});
            }
        }
    }
    int ans = INF;
    for(int i=1;i<=1000;i++) ans = min(ans,dis[n][i]);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}