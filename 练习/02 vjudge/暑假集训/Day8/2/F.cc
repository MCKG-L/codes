#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
/*
树的直径性质：从任意节点出发，dfs到达最远的点一定是树的直径的一个端点
可以预处理除直径两个端点到每一个点的距离，则取Max就可以快速求出以任意点为根节点是树的价值
本题需要直到两个值即可求出答案：
1、根节点1到所有节点的深度
2、树的两个直径到所有节点的深度，取Max，得到以任意节点为根时的最大深度
*/
vector<int> e[N];
int dep1[N],dep2[N],dep3[N];
int n,k,c;
void dfs(int dep[],int u,int p){
    for(auto v : e[u]) if(v != p) dep[v] = dep[u] + 1,dfs(dep,v,u);
}
void solve(){
    cin >> n >> k >> c;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=0;i<n-1;i++){
        int u,v;cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dep1[1] = 0;dfs(dep1,1,1);//求出根节点1到所有点的深度
    int p1 = max_element(dep1+1,dep1+n+1)-dep1;//得到以1为根节点时的最大深度的编号，即为直径端点之一
    dep2[p1] = 0;dfs(dep2,p1,p1);//以直径端点为根节点深度遍历
    int p2 = max_element(dep2+1,dep2+n+1)-dep2;//得到另一个直径端点
    dep3[p2] = 0;dfs(dep3,p2,p2);//以另一个直径端点为根节点深度优先遍历
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans,max(dep2[i],dep3[i])*k-c*dep1[i]);
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}