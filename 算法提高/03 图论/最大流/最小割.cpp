#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 100,M = 2010;
/*洛谷P1344
求一个无向图的最小割的容量，以及最小边数
技巧 加入一个偏移量mod，权值变为c * mod + 1
这样一遍Dinic求出最大流ans，得到的ans / mod即为最小割，ans % mod即为最小边数
*/
struct Node{
    int v,c,ne;
}e[M];
int h[N],d[N],cur[N],idx = 1;
void add(int a,int b,int c){
    e[++idx] = {b,c,h[a]};
    h[a] = idx;
}
void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        add(u,v,c * 1001 + 1);
        add(v,u,0);
    }
    auto bfs = [&]()->bool{
        memset(d,0,sizeof d);
        d[1] = 1;
        queue<int> q;
        q.push(1);
        while(q.size()){
            auto ver = q.front();q.pop();
            for(int i=h[ver];i;i=e[i].ne){
                int v = e[i].v;
                if(!d[v] && e[i].c){
                    d[v] = d[ver] + 1;
                    if(v == n) return true;
                    q.push(v);
                }
            }
        }
        return false;
    };
    auto dfs = [&](auto dfs,int u,int mf)->int{
        if(u == n) return mf;
        int sum = 0;
        for(int i=cur[u];i;i=e[i].ne){
            int v = e[i].v;
            cur[u] = i;
            if(d[v] == d[u] + 1 && e[i].c){
                int t = dfs(dfs,v,min(e[i].c,mf));
                sum += t;
                mf -= t;
                e[i].c -= t;
                e[i^1].c += t;
                if(mf == 0) break;
            }
        }
        if(sum == 0) d[u] = 0;
        return sum;
    };
    int ans = 0;
    while(bfs()){
        memcpy(cur,h,sizeof h);
        ans += dfs(dfs,1,inf);
    }
    cout << ans / 1001 << ' ' << ans % 1001 << endl;
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
