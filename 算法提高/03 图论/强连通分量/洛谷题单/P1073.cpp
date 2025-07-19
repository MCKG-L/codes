#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> cost(n + 1);
    vector<vector<PII>> a(3 * n + 1);
    for(int i=1;i<=n;i++) cin >> cost[i];
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        a[u].push_back({v,0});
        a[u+n].push_back({v+n,0});
        a[u+2*n].push_back({v + n * 2,0});
        if(c == 2){
            a[v].push_back({u,0});
            a[v+n].push_back({u + n,0});
            a[v+2*n].push_back({u + 2 * n,0});
        }
    }
    for(int i=1;i<=n;i++){
        a[i].push_back({i + n,cost[i]});
        a[i + n].push_back({i + n * 2,-cost[i]});
    }
    vector<int> st(n * 3 + 1,false);
    queue<int> q;
    q.push(1);
    st[1] = 1;
    vector<int> dis(n * 3 + 10,inf);
    dis[1] = 0;
    while(q.size()){
        auto ver = q.front();q.pop();
        st[ver] = 0;
        for(auto [v,c] : a[ver]){
            if(c + dis[ver] < dis[v]){
                dis[v] = dis[ver] + c;
                if(!st[v]){
                    q.push(v);
                    st[v] = 1;
                }
            }
        }
    }
    cout << max(-dis[n],-dis[3*n]) << endl;
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
