#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 2e5 + 10;
/* abc_406_f
给出一棵树，有q次询问，每次两种操作：
1、将x节点的权值增大w
2、给出一条边，问断开这条边后，形成两个子树的权值之和的绝对差值
考察快速求子树的权值和，考虑到每个子树的dfn序列是连续的，所以可以将问题转化为整数上的序列问题
使用树状数组维护单点修改，区间查询
*/
struct Fenwick{
    vector<int> tr;
    int n;
    Fenwick(int n){
        this->n = n;
        tr.assign(n + 1,0);
    }
    void add(int x,int c){
        for(;x<=n;x+=x&-x) tr[x] += c;
    }
    int ask(int x){
        int res = 0;
        for(;x;x-=x&-x) res += tr[x];
        return res;
    }
    int ask(int l,int r){
        return ask(r) - ask(l-1);
    }
};
void solve(){
    int n;cin >> n;
    vector<vector<int>> a(n + 1);
    vector<PII> e(n + 1);
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        e[i] = {u,v};
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> dfn(n + 1),siz(n + 1);
    int ts = 0;
    auto dfs = [&](auto dfs,int u,int fa)->void{
        dfn[u] = ++ ts;siz[u] = 1;
        for(auto v : a[u]){
            if(v == fa) continue;
            dfs(dfs,v,u);
            siz[u] += siz[v];
        }
    };
    dfs(dfs,1,0);
    int q;cin >> q;
    Fenwick fenwick(n);
    for(int i=1;i<=n;i++) fenwick.tr[i] = i & -i;
    int tot = n;
    while(q --){
        int op;cin >> op;
        if(op == 1){
            int x,w;
            cin >> x >> w;
            tot += w;
            fenwick.add(dfn[x],w);
        }else{
            int x;cin >> x;
            auto [u,v] = e[x];
            if(dfn[u] < dfn[v]) swap(u,v);
            // cerr << u << endl;
            int t = fenwick.ask(dfn[u],dfn[u]+siz[u]-1);
            cout << abs(tot-2*t) << endl;
        }
    }
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