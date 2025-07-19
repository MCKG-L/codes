#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e3 + 10,M = 1e5 + 10;
/*Johnson改进的全源最短路算法 --可以处理带负边权的情况
时间复杂度O(nmlogm) n <= 1000,m <= 1000
跑n次堆优化版本的DIjkstra算法
思想：引入一个势能函数h,将原图改造：W(u,v) = W0(u,v) + h[u] - h[v]
新图与旧图之间的最短路关系：W(u,v) = W0(u,v) + h[u] - h[v]
这样可以保证在改造之后，所有边权都非负，可以使用Dijkstra算法
做法：
1、引入一个虚拟源点0，向每个点之间连接边权为0的边
2、引入一个势能函数h[N]，(使用spfa算法求虚拟源点到每个点的最短路,即为h[N])
3、在改造后的新图上，以每个点每起点跑n遍堆优化版Dijkstra算法
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<PII>> a(n + 1);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        a[u].push_back({v,c});
    }
    for(int i=1;i<=n;i++) a[0].push_back({i,0});
    vector<int> h(n + 1,inf);
    auto spfa = [&]()->void{
        queue<int> q;
        vector<bool> st(n + 1);
        vector<int> cnt(n + 1);
        h[0] = 0,st[0] = 1;
        q.push(0);
        while(q.size()){
            int u = q.front();q.pop();
            st[u] = 0;
            for(auto [v,c] : a[u]){
                if(h[v] > h[u] + c){
                    h[v] = h[u] + c;
                    cnt[v] = cnt[u] + 1;
                    if(cnt[v] > n + 1){
                        cout << "-1" << endl;
                        exit(0);
                    }
                    if(!st[v]){
                        st[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    };
    spfa();
    for(int i=1;i<=n;i++){
        for(auto &it : a[i]){
            it.second += h[i] - h[it.first];

        }
    }
    vector<int> dis(n + 1,inf);
    auto Dijkstra = [&](int s)->void{
        // dis.assign(n + 1,inf);
        for(int i=1;i<=n;i++) dis[i] = inf;
        priority_queue<PII,vector<PII>,greater<PII>> heap;
        vector<int> st(n + 1);
        dis[s] = 0;heap.push({0,s});
        while(heap.size()){
            auto [d,u] = heap.top();heap.pop();
            if(st[u]) continue;
            st[u] = 1;
            for(auto [v,c] : a[u]){
                if(dis[v] > d + c){
                    dis[v] = d + c;
                    heap.push({dis[v],v});
                }
            }
        }
    };
    for(int i=1;i<=n;i++){
        int ans = 0,off = 1e9;
        Dijkstra(i);
        for(int j=1;j<=n;j++){
            if(dis[j] == inf){
                ans += off * j;
            }else{
                ans += (dis[j] - h[i] + h[j]) * j;
            }
        }
        cout << ans << endl;
    }
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
