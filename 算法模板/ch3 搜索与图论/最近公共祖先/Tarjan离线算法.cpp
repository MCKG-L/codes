#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
typedef pair<int,int> PII;
vector<vector<int>> a(N);
vector<vector<PII>> query(N);
int n,q,s;
int p[N],ans[N];
bool st[N];
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void tarjan(int u){
    st[u] = true;
    for(auto v : a[u]){
        if(st[v]) continue;
        tarjan(v);
        p[v] = u;
    }
    for(auto [v,i] : query[u]){
        if(st[v]) ans[i] = find(v);
    }
}
void solve(){
    cin >> n >> q >> s;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=q;i++){
        int u,v;
        cin >> u >> v;
        query[u].push_back({v,i});
        query[v].push_back({u,i});
    }
    tarjan(s);
    for(int i=1;i<=q;i++) cout << ans[i] << endl;
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
