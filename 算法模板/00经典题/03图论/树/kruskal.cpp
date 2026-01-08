#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
/* 题目来源：abc_383_e
给一张简单无向图，n个点m条边，每条边有一个权值w，给定两个点集A和B
保证A和B的元素没有交集，定义价值f(a,b)为图中从点a到点b的所有路径中权重最小值，其中路径的权重定义为
该路径中所有边权的最大值,问：可以重新排列B数组，使得sum(f(a,b))的值最小，求其最小值

贪心：对于两个连通块中的点，尽可能使用最小的边权匹配尽可能大的对数。
所以需要统计每个连通块中的A中的点和B中的点的数目
考虑cruskal算法过程，将所有边按照排序，如果当前边的两端点u,v，属于同一个连通块，则基于贪心思想，u,v已经在之前考虑过了
当u,v不属于同一个连通块，则当前u所在的连通块和v所在的连通块，可以通过当前的边联通，且路径价值是最小的，为当前边的权值w

使用并查集，维护点的联通状态以及每个联通块中还未被处理的A中点个数和B中点个数

每次合并连通块时权值贡献为：w * min(sz1[v],sz2[v]);
*/
struct Node{
    int u,v,val;
    bool operator<(const Node &p)const{
        return val < p.val;
    }
};
int f[N];
int find(int x){
    while(f[x] != x) x = f[x] = f[f[x]];
    return x;
}
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) f[i] = i;
    vector<Node> a(m + 1);
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[i] = {u,v,w};
    }  
    sort(a.begin()+1,a.begin()+1+m);
    vector<int> sz1(n + 1,0),sz2(n + 1,0);
    for(int i=1;i<=k;i++){
        int x;cin >> x;sz1[x] ++;
    }
    for(int i=1;i<=k;i++){
        int x;cin >> x;sz2[x] ++;
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        auto [u,v,w] = a[i];
        u = find(u),v = find(v);
        if(u == v) continue;
        f[u] = v;
        sz1[v] += sz1[u];sz2[v] += sz2[u];
        int Min = min(sz1[v],sz2[v]);
        ans += Min * w;
        sz1[v] -= Min,sz2[v] -= Min;
        sz1[u] = sz2[u] = 0;
    }
    cout << ans << endl;
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