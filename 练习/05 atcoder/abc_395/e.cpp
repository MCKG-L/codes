#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 5e5 + 10,inf = 1e18;
vector<vector<PII>> a;
int dis[N];
bool st[N];
void Dijkstra(int n){
    for(int i=1;i<=n;i++){
        dis[i] = inf;st[i] = false;
    }
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    dis[1] = 0;
    while(heap.size()){
        auto [d,ver] = heap.top();
        heap.pop();
        if(st[ver]) continue;
        st[ver] = true;
        for(auto [v,s] : a[ver]){
            if(d + s < dis[v]){
                dis[v] = s + d;
                heap.push({dis[v],v});
            }
        }
    }
}
void solve(){
    int n,m,x;
    cin >> n >> m >> x;
    a.resize(2 * n + 10);
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back({v,1});
        a[n+v].push_back({n+u,1});
        // a[u].push_back({u+})
    }
    //分层图
    for(int i=1;i<=n;i++){
        a[i].push_back({i+n,x});
        a[i+n].push_back({i,x});
    }
    Dijkstra(n << 1);
    cout << min(dis[n],dis[n+n]) << endl;
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