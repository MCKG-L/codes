#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
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