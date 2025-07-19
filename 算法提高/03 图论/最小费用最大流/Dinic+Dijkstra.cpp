#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e3 + 10,M = 1e5 + 10;
struct Node{
    int v,c,d,ne;
}e[M];
int h[N],idx = 1;
int dis[N],cur[N];
bool vis[N],st[N];
int hv[N];
void add(int a,int b,int c,int d){
    e[++idx] = {b,c,d,h[a]};
    h[a] = idx;
}
void solve(){
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int u,v,c,w;
        cin >> u >> v >> c >> w;
        add(u,v,c,w);
        add(v,u,0,-w);//反向边
    }
    auto Dijkstra = [&]()->bool{
        for(int i=1;i<=n;i++) dis[i] = inf,st[i] = 0;
        priority_queue<PII,vector<PII>,greater<PII>> heap;
        heap.push({0,s});
        dis[s] = 0;
        while(heap.size()){
            auto [d,u] = heap.top();heap.pop();
            if(st[u]) continue;
            st[u] = 1;
            for(int i=h[u];i;i=e[i].ne){
                int v = e[i].v,w = e[i].d;
                if(e[i].c && dis[v] > d + w + hv[u] - hv[v]){
                    dis[v] = d + w + hv[u] - hv[v];
                    heap.push({dis[v],v});
                }
            }
        }
        return dis[t] != inf;
    };
    int cost = 0,flow = 0;
    //多路增广
    auto dfs = [&](auto &dfs,int u,int mf)->int{
        if(u == t) return mf;
        vis[u] = 1;
        int sum = 0;
        for(int i=cur[u];i;i=e[i].ne){
            int v = e[i].v,w = e[i].d;
            cur[u] = i;//当前弧优化
            if(e[i].c && !vis[v] && hv[v] == hv[u] + w){
                int f = dfs(dfs,v,min(mf,e[i].c));
                //更新残留网
                e[i].c -= f;
                e[i^1].c += f;
                cost += f * w;
                sum += f;
                mf -= f;
                if(mf == 0) break;//余量优化
            }
        }
        vis[u] = 0;
        if(sum == 0) dis[u] = inf;
        return sum;
    };
    auto dinic = [&]()->int{
        int flow = 0;
        while(Dijkstra()){
            for(int i=1;i<=n;i++) hv[i] += dis[i];
            memcpy(cur,h,sizeof h);
            int f;
            //一次spfa，多次dfs增广
            do{
                f = dfs(dfs,s,inf); 
                flow += f;
            }while(f > 0);
        }
        return flow;
    };
    flow = dinic();
    cout << flow << ' ' << cost << endl;
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
