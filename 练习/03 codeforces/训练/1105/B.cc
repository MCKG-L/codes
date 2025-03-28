#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,M = 5e5 + 10;
int h[N],ne[M],e[M],w[M],idx;
int n,m;
int dis[N];
bool st[N];
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void Dijkstra(int s){
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    for(int i=1;i<=n;i++) dis[i] = 1e18;
    dis[s] = 0;
    heap.push({0,s});
    while(heap.size()){
        auto [d,t] = heap.top();heap.pop();
        if(st[t]) continue;
        st[t] = 1;
        for(int i=h[t];~i;i=ne[i]){
            int j = e[i];
            if(dis[j] > d + w[i]){
                dis[j] = d + w[i];
                heap.push({dis[j],j});
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) h[i] = -1,st[i] = 0;
    idx = 0;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w),add(v,u,w);
    }
    Dijkstra(n);
    //保存最短路径的转移关系
    vector<int> ind(n+10);
    vector<vector<int>> g(n+10);
    for(int k=1;k<=n;k++){
        for(int i=h[k];~i;i=ne[i]){
            int j = e[i];
            if(dis[j] + w[i] == dis[k]){
                // j -> k
                ind[k] ++;
                g[j].push_back(k);
            }
        }
    }
    vector<int> ans(n+10);//每个点的必胜状态/必败状态
    //终点n处为必败态 ans[n] = 0;
    //利用拓扑原理 从后向前递推状态
    queue<int> q;q.push(n);
    while(q.size()){
        int k = q.front();q.pop();
        for(auto v : g[k]){
            //k -> v
            ind[v] --;
            if(ans[v] == 0) ans[v] = ans[k] ^ 1;
            if(ind[v] == 0) q.push(v);
        }
    }
    if(ans[1]) cout << "Little M is the winner." << endl;
    else cout << "Little I is the winner." << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}