#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
struct DSU{
    std::vector<int> f,siz;
    DSU(int n): f(n),siz(n,1){std::iota(f.begin(),f.end(),0);}
    int find(int x){
        while(f[x] != x) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int a,int b){return find(a) == find(b);}
    void unite(int a,int b){
        a = find(a);b = find(b);
        if(a == b) return;
        siz[a] += siz[b];
        f[b] = a;
    }
    int size(int x) {return siz[find(x)];}
};
//离线 + DSU
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    vector<array<int,3>> p(m);
    for(int i=0;i<m;i++){
        int u,v,w;cin >> u >> v;
        u --,v --;
        w = max(h[u],h[v]);
        p[i] = {w,u,v};
    }
    sort(p.begin(),p.end());
    int q;cin >> q;
    vector<array<int,4>> qry(q);
    vector<bool> ans(q);
    for(int i=0;i<q;i++){
        int a,b,e;cin >> a >> b >> e;
        a --,b --;
        qry[i] = {h[a]+e,a,b,i};
    }
    sort(qry.begin(),qry.end());
    int it = 0;
    DSU dsu(n);
    for(auto [H,u,v,i] : qry){
        while(it < m && p[it][0] <= H){
            dsu.unite(p[it][1],p[it][2]);
            it ++;
        }
        if(dsu.same(u,v)) ans[i] = 1;
    }
    for(int i=0;i<q;i++){
        if(ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    cout << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}