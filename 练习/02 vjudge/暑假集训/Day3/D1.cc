#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10,M = 2 * N;
int h[N],e[M],ne[M],idx;
int ans[N];
bool st[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
int dfs(int u){
    if(st[u]) return 0;
    st[u] = 1;
    int cnt = 0;
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        cnt += dfs(j);
    }
    if(cnt == 0) cnt = 1;
    ans[u] = cnt;
    return cnt;
}
void solve(){
    idx = 0;
    memset(st,false,sizeof st);
    memset(h,-1,sizeof h);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        add(u,v),add(v,u);
    }
    dfs(1);
    cin >> m;
    while(m--){
        int x,y;
        cin >> x >> y;
        int res = ans[x] * ans[y];
        cout << res << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}