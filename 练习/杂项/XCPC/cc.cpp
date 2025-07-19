#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e6 + 10,mod = 998244353,inf = 1e18;
struct DSU{
    std::vector<int> f,siz;
    DSU(int n):f(n+1),siz(n+1,1){std::iota(f.begin(),f.end(),0);}
    int find(int x){
        while(f[x] != x) x = f[x] = f[f[x]];
        return x;
    }
    void unite(int a,int b){
        a = find(a),b = find(b);
        if(a == b) return;
        f[b] = a;
        siz[a] += siz[b];
    }
    bool same(int a,int b){
        return find(a) == find(b);
    }
    int size(int x){
        return siz[find(x)];
    }
};
void solve(){
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    DSU dsu1(n),dsu2(n);
    map<PII,int> mp;
    for(int i=1;i<=m1;i++){
        int u,v;cin >> u >> v;
        dsu1.unite(u,v);
    }
    for(int i=1;i<=m2;i++){
        int u,v;cin >> u >> v;
        dsu2.unite(u,v);
    }
    for(int i=1;i<=n;i++){
        mp[{dsu1.find(i),dsu2.find(i)}] ++;
    }
    int ans = 0;
    for(auto [_,cnt] : mp){
        ans += cnt * (cnt - 1) / 2;
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