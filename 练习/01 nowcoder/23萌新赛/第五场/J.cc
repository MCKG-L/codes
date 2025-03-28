#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int h[N],e[N],w[N],ne[N],idx;
int n;
int dep[N];
void init(){
    memset(h,-1,sizeof h);
    memset(dep,0,sizeof dep);
    idx = 0;
}
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void dfs(int u,int f){
    dep[u] = dep[f] + 1;
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(j == f) continue;
        dfs(j,u);
    }
}
void solve(){
    init();
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        add(a,b);add(b,a);
    }
    for(int i=1;i<=n;i++) cin >> w[i];
    dfs(1,0);
    sort(w+1,w+n+1);
    sort(dep+1,dep+n+1);
    // for(int i=1;i<=n;i++){
    //     cout << w[i] << ' ' << dep[i] << endl;
    // }
    int ans = 0;
    for(int i=1;i<=n;i++) ans += dep[i]*w[i];
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}
