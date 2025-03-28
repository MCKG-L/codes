#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
//树的直径
int n,k;
void solve(){
    cin >> n >> k;
    vector<vector<int>> p(n+1);
    vector<bool> mask(n+1,false);
    for(int i=0;i<k;i++){
        int x;cin >> x;
        mask[x] = true;
    }
    for(int i=0;i<n-1;i++){
        int u,v;cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    //匿名函数
    auto bfs=[&](int s) -> vector<int> {
        vector<int> d(n+1,-1);
        queue<int> q;q.push(s);
        d[s] = 0;
        while(q.size()){
            int u = q.front();q.pop();
            for(auto v : p[u]){
                if(d[v] != -1) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        return d;
    };
    auto d1 = bfs(1);
    int L = -1,M = -1;
    for(int i=1;i<=n;i++){
        if(!mask[i]) continue;
        if(d1[i] > M){
            M = d1[i];
            L = i;
        }
    }
    auto d2 = bfs(L);
    int R = -1;M = -1;
    for(int i=1;i<=n;i++){
        if(!mask[i]) continue;
        if(d2[i] > M){
            M = d2[i];
            R = i;
        }
    }
    auto d3 = bfs(R);
    int ans = 1e8;
    for(int i=1;i<=n;i++) ans = min(ans,max(d2[i],d3[i]));
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}