#include <iostream>
#include <cstring>
#define int long long
#define endl '\n'
using namespace std;
const int N = 4e5 + 10;
int h[N],ne[N],e[N],idx;
int ans[N];
bool st[N];
int n,m,q;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
int dfs(int x){
    if(st[x]) return 0;
    st[x] = 1;
    int cnt = 0;
    for(int i=h[x];i!=-1;i=ne[i]){
        int j = e[i];
        cnt += dfs(j);
    }
    if(cnt == 0) cnt = 1;
    ans[x] = cnt;
    return cnt;
}
void solve(){
    memset(h,-1,sizeof h);idx = 0;
    memset(ans,0,sizeof ans);
    memset(st,0,sizeof st);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v,s;
        cin >> u >> v;
        // s = u + v;
        // u = min(u,v),v = s - u;
        // add(u,v);
        add(u,v),add(v,u);
    }
    dfs(1);
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << ans[x]*ans[y] << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}