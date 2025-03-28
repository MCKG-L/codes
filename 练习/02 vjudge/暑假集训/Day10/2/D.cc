#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 11;
vector<int> p[N];
bool st[N][N];
int n,m,t,ans;
void dfs(int u){
    if(u > n){
        for(int i=0;i<t;i++){
            if(p[i].size() == 0) return;
        }
        ans ++;return;
    }
    //遍历所有组
    for(int i=0;i<t;i++){
        bool f = 1;
        for(auto i : p[i]){
            if(st[i][u]){
                f = 0;break;
            }
        }
        if(f){
            p[i].push_back(u);
            dfs(u+1);
            p[i].pop_back();
        }
        // if(p[i].size() == 0) return;
    }
}
void solve(){
    cin >> n >> t >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        st[u][v] = 1;st[v][u] = 1;
    }
    dfs(1);//暴力搜索
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}