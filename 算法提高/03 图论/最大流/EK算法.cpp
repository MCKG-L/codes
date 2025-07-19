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
int mf[N],pre[N];
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
    auto bfs = [&]()->bool{//找增广链
        memset(mf,0,sizeof mf);
        queue<int> q;
        q.push(s);mf[s] = inf;
        while(q.size()){
            int k = q.front();q.pop();
            for(int i=h[k];i;i=edge[i].ne){
                int v = edge[i].v;
                if(mf[v] == 0 && edge[i].c){
                    mf[v] = min(mf[k],edge[i].c);
                    pre[v] = i;
                    q.push(v);
                    if(v == t) return true;
                }
            }
        }
        return false;
    };
    auto EK = [&]()->int{
        int flow = 0;
        while(bfs()){
            int v = t;
            while(v != s){//更新残留网
                int i = pre[v];
                edge[i].c -= mf[t];
                edge[i^1].c += mf[t];
                v = edge[i^1].v;
            }
            flow += mf[t];
        }
        return flow;
    };
    cout << EK() << endl;
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
