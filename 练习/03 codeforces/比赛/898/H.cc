#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
//题目保证给出的是一个连通图 n条边 任意两点间最多由一条边 所以图中一定有且只有一个环
/*
思路：先找到b到环的最近的点v，再分别算出a,b到v的距离
*/
bool st[N];
vector<vector<int>> p(N);
int In = -1;
bool dfs1(int u,int f){
    st[u] = 1;
    for(auto v : p[u]){
        if(v == f) continue;
        if(st[v]){
            In = v;return 1;
        }else{
            if(dfs1(v,u)) return 1;
        }
    }
    return 0;
}
int dfs2(int u){
    st[u] = 1;
    int dis = N;
    for(auto  v : p[u]){
        if(v == In){
            return 1;
        }
        if(st[v] == 0){
            int d = dfs2(v) + 1;
            dis = min(dis,d);
        }
    }
    return dis;
}
void solve(){
    int a,b,n;
    cin >> n >> a >> b;
    for(int i=1;i<=n;i++) p[i].clear(),st[i] = 0;
    for(int i=0;i<n;i++){
        int u,v;cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    dfs1(b,-1);
    for(int i=0;i<=n;i++) st[i] = 0;
    int d1,d2;
    if(In == a) d1 = 0;
    else d1 = dfs2(a);
    for(int i=0;i<=n;i++) st[i] = 0;
    if(In == b) d2 = 0;
    else d2 = dfs2(b);
    // cout << In << ' ' << d1 << ' ' << d2 << endl;
    if(d2 < d1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}