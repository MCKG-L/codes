#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//树的直径
const int N = 2e5 + 10;
int n,k;
int dep1[N],dep2[N],dep3[N];
vector<int> p[N];
void bfs(int dep[],int s){
    vector<bool> st(n+1,false);
    queue<int> q;q.push(s);
    dep[s] = 0;st[s] = 1;
    while(q.size()){
        int u = q.front();q.pop();
        for(auto v : p[u]){
            if(st[v]) continue;
            st[v] = true;
            dep[v] = dep[u] + 1;
            q.push(v);
        }
    }
}
void solve(){
    cin >> n >> k;
    for(int i=0;i<=n;i++) p[i].clear();
    vector<bool> mask(n+1,false);
    for(int i=0;i<k;i++){
        int x;cin >> x;
        mask[x] = 1;
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    if(k == 1){
        cout << 0 << endl;
        return;
    }
    dep1[1] = 0;
    bfs(dep1,1);
    int L = -1,M = -1;
    for(int i=1;i<=n;i++){
        if(!mask[i]) continue;
        if(dep1[i] > M){
            M = dep1[i];
            L = i;
        }
    }
    dep2[L] = 0;
    bfs(dep2,L);
    int R = -1;M = -1;
    for(int i=1;i<=n;i++){
        if(!mask[i]) continue;
        if(dep2[i] > M){
            M = dep2[i];
            R = i;
        }
    }
    dep3[R] = 0;
    bfs(dep3,R);
    int ans = 1e8;
    for(int i=1;i<=n;i++){
        ans = min(ans,max(dep2[i],dep3[i]));
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}