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
int h[N],mf[N],pre[N],idx = 1;
void add(int a,int b,int c,int d){
    e[++idx] = {b,c,d,h[a]};
    h[a] = idx;
}
int st[N],dis[N];
void solve(){
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    for(int i=0;i<m;i++){
        int u,v,c,w;
        cin >> u >> v >> c >> w;
        add(u,v,c,w);
        add(v,u,0,-w);
    }
    auto spfa = [&]()->bool{
        // dis.assign(n + 1,inf);
        memset(dis,0x3f,sizeof dis);
        memset(st,false,sizeof st);
        memset(mf,0,sizeof mf);
        queue<int> q;q.push(s);
        dis[s] = 0,mf[s] = inf;
        st[s] = 1;
        while(q.size()){
            auto ver = q.front();q.pop();
            st[ver] = false;
            for(int i=h[ver];i;i=e[i].ne){
                auto [v,c,w,_] = e[i];
                if((dis[v] > dis[ver] + w) && c){
                    dis[v] = dis[ver] + w;
                    mf[v] = min(mf[ver],c);
                    pre[v] = i;
                    if(!st[v]) q.push(v),st[v] = 1;
                }
            }
        }
        return mf[t] > 0;
    };
    int flow = 0,cost = 0;
    auto EK = [&]()->int{
        while(spfa()){
            int v = t;
            while(v != s){
                int i = pre[v];
                e[i].c -= mf[t];
                e[i^1].c += mf[t];
                v = e[i^1].v;
            }
            flow += mf[t];
            cost += dis[t] * mf[t];
        }
    };
    EK();
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
