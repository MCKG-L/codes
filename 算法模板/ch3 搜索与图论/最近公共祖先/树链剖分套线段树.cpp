#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,mod = 201314;
int n,m,ts;
int siz[N],son[N],top[N],dep[N],fa[N],id[N];
vector<vector<int>> a(N);
struct Node{
    int l,r;
    int sum,add;
}tr[N<<2];
typedef struct Query{
    int k,z;
    int tag,id;
}Query;
vector<Query> alls;
void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}
void build(int u,int l,int r){
    tr[u].l = l,tr[u].r = r;
    if(l == r) tr[u] = {l,r,0,0};
    else{
        int mid = l + r >> 1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        // pushup(u);
    }
}
void pushdown(int u){
    if(tr[u].add){
        tr[u<<1].add += tr[u].add;
        tr[u<<1|1].add += tr[u].add;
        tr[u<<1|1].sum += (tr[u<<1|1].r-tr[u<<1|1].l+1)*tr[u].add;
        tr[u<<1].sum += (tr[u<<1].r-tr[u<<1].l+1)*tr[u].add;
        tr[u].add = 0;
    }
}
void modify(int u,int l,int r,int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += (tr[u].r-tr[u].l+1)*d;
        tr[u].add += d;
    }else{//跨区间 一定要把懒标记传递到子节点 pushdown
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,d);
        if(r > mid) modify(u<<1|1,l,r,d);                                                 
        pushup(u);
    }
}
void modify(int u,int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        modify(1,id[top[u]],id[u],1);
        u = fa[top[u]];
    }
    if(dep[u] > dep[v]) swap(u,v);
    modify(1,id[u],id[v],1);
}
int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    //跨区间
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if(l <= mid) sum += query(u<<1,l,r);
    if(r > mid) sum += query(u<<1|1,l,r);
    return sum;
}
int query(int u,int v){
    int ans = 0;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u,v);
        ans += query(1,id[top[u]],id[u]);
        u = fa[top[u]];
    }
    if(dep[u] > dep[v]) swap(u,v);
    ans += query(1,id[u],id[v]);
    return ans;
}
void dfs1(int u,int father){
    dep[u] = dep[father] + 1,siz[u] = 1,fa[u] = father;
    for(auto v : a[u]){
        if(v == father) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v]) son[u] = v;
    }
}
void dfs2(int u,int t){
    id[u] = ++ ts;
    top[u] = t;//t为所在重链的链头
    if(son[u] == 0) return;
    //搜重儿子
    dfs2(son[u],t);
    //搜轻儿子
    for(auto v : a[u]){
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v,v);
    }
}
void solve(){
    cin >> n >> m;
    for(int i=2;i<=n;i++){
        int x;cin >> x;
        x ++;
        a[x].push_back(i);
        a[i].push_back(x);
    }
    build(1,1,n);
    dfs1(1,0);
    dfs2(1,1);
    for(int i=0;i<m;i++){
        int l,r,z;
        cin >> l >> r >> z;
        l ++,r ++,z ++;
        alls.push_back({l-1,z,0,i});
        alls.push_back({r,z,1,i});
    }
    sort(alls.begin(),alls.end(),[&](Query q1,Query q2){
        return q1.k < q2.k;
    });
    vector<int> ans(m,0);
    int now = 1;
    for(auto [k,z,tag,i] : alls){
        while(now <= k) modify(1,now ++);
        if(tag) ans[i] += query(1,z);
        else ans[i] -= query(1,z);
        ans[i] += mod;
        ans[i] %= mod;
    }
    for(auto x : ans) cout << x << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}