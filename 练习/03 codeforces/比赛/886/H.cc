#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10,INF = 1e18;
vector<PII> e[N];
int dis[N];
int n,m;
int dfs(int u){
    for(auto [x,y] : e[u]){
        if(dis[x] != INF){
            if(dis[x] != dis[u] + y) return 0;
        }else{
            dis[x] = dis[u] + y;
            if(!dfs(x)) return 0;
        }
    }
    return 1;
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        dis[i] = INF;
        e[i].clear();
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        e[a].push_back({b,c});
        e[b].push_back({a,-c});
    }
    //判断建的图是否合理 -> dfs枚举每一个连通块 判断连通块中所有点到连通块一点的距离是否唯一
    int f = 1;
    for(int i=1;i<=n;i++){
        if(dis[i] != INF) continue;//已经枚举过 已经出现在之前的连通块中
        dis[i] = 0;
        f = f && dfs(i);
    }
    if(f) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}