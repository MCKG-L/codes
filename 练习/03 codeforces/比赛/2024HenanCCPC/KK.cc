#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve(){
    int n;cin >> n;
    vector<int> a(n + 10);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<vector<int>> g(n + 10);
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int cnt = 0;//满足条件的子结点个数
    auto dfs = [&](auto dfs,int u,int fa) -> void{
        for(auto v : g[u]){
            if(v == fa) continue;
            if(2 * a[v] >= a[u]) cnt ++;
            dfs(dfs,v,u);
        }
    };
    int ans = 0;
    auto dfs2 = [&](auto dfs2,int u,int fa) -> void{
        if(cnt == n - 1) ans ++;
        for(auto v : g[u]){
            if(v == fa) continue;
            //u与v换根 -->只会影响u与v之间的父子关系，其他结点关系不受影响
            if(2 * a[v] >= a[u]) cnt --;
            if(2 * a[u] >= a[v]) cnt ++;
            dfs2(dfs2,v,u);
            if(2 * a[v] >= a[u]) cnt ++;//回溯
            if(2 * a[u] >= a[v]) cnt --;
        }
    };
    dfs(dfs,1,0);
    dfs2(dfs2,1,0);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}