#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 1e5 + 10;
/* acwing P3403 北京大学机试题
某国正处于激烈的内战之中，该国的各个城市按照支持领导人的不同分属两个阵营。
作为一个商人，M先生并不关心政治，但他能够感受到目前事态的严峻。
你需要帮助他尽快回家。
出于安全的考虑，你所提供的回家线路中，最多只能包含一条连接两个不同阵营城市的道路。
请你计算，M先生回家所需花费的最短时间。
建立分层图 跑最短路
*/
int n,m;
void solve(){
    if(n == 0){
        return;
    }
    cin >> m;
    vector<vector<PII>> a(2 * n + 1);
    vector<array<int,3>> e(m);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        e[i] = {u,v,c};
    }
    vector<int> color(2 * n + 1);
    for(int i=1;i<=n;i++){
        cin >> color[i];
        color[i + n] = color[i];
    }
    auto add = [&](int u,int v,int c)->void{
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    };
    for(auto [u,v,c] : e){
        if(color[u] != color[v]){
            if(color[u] == 1){
                a[u].push_back({v+n,c});
            }else{
                a[v].push_back({u+n,c});
            }
        }else{
            add(u,v,c);
            add(u+n,v+n,c);
        }
    }
    auto Dijkstra = [&](int sta,int ed)->int{
        priority_queue<PII,vector<PII>,greater<PII>> heap;
        vector<int> dis(2 * n + 1,inf);
        dis[sta] = 0;
        heap.push({0,sta});
        vector<bool> st(n * 2 + 1);
        while(heap.size()){
            auto [d,ver] = heap.top();heap.pop();
            if(st[ver]) continue;
            st[ver] = 1;
            for(auto [v,c] : a[ver]){
                if(d + c < dis[v]){
                    dis[v] = d + c;
                    heap.push({dis[v],v});
                }
            }
        }
        return min(dis[ed],dis[ed+n]);
    };
    int t = Dijkstra(1,2);
    cout << (t == inf ? -1 : t) << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(cin >> n) solve();
    return 0;
}
