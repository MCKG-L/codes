#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 210,M = 10010;
struct Node{
    int v,c,ne;
}edge[M];
int h[N],idx = 1;
int d[N],cur[N];
void add(int a,int b,int c){
    edge[++idx] = {b,c,h[a]};
    h[a] = idx;
}
void solve(){
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,0);//反向边
    }
    auto bfs = [&]()->bool{//对点分层，寻找增广边
        memset(d,0,sizeof d);
        queue<int> q;
        q.push(s),d[s] = 1;
        while(q.size()){
            int k = q.front();q.pop();
            for(int i=h[k];i;i=edge[i].ne){
                int v = edge[i].v;
                if(d[v] == 0 && edge[i].c){
                    d[v] = d[k] + 1;
                    q.push(v);
                    if(v == t) return true;
                }
            }
        }
        return false;
    };
    //多路增广
    auto dfs = [&](auto &dfs,int u,int mf)->int{
        if(u == t) return mf;
        int sum = 0;
        for(int i=cur[u];i;i=edge[i].ne){
            int v = edge[i].v;
            cur[u] = i;//当前弧优化
            if(d[v] == d[u] + 1 && edge[i].c){
                int f = dfs(dfs,v,min(mf,edge[i].c));
                //更新残留网
                edge[i].c -= f;
                edge[i^1].c += f;
                sum += f;
                mf -= f;
                if(mf == 0) break;//余量优化
            }
        }
        if(sum == 0) d[u] = 0;//残枝优化
        return sum;
    };
    auto dinic = [&]()->int{
        int flow = 0;
        while(bfs()){
            memcpy(cur,h,sizeof h);
            flow += dfs(dfs,s,inf);
        }
        return flow;
    };
    cout << dinic() << endl;
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
