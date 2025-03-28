#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 3e5 + 10,M = 2 * N,INF = 2e9;
int h[N],ne[M],e[M],w[M],idx;
char dic[N];
int n;
int dp[N];
int ind[N];
void add(int a,int b,int c){
    ind[a] ++;ind[b] ++;
    ne[idx] = h[a];
    w[idx] = c;
    e[idx] = b;
    h[a] = idx ++;
}
void init(){
    idx = 0;
    for(int i=1;i<=n;i++){
        dp[i] = INF;
        ind[i] = 0;
    }
}
map<int,char> mp = {{1,'L'},{2,'R'},{3,'U'}};
void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(j == fa) continue;
        dp[j] = dp[u];
        if(dic[u] != mp[w[i]]) dp[j] ++;
        dfs(j,u);
    }
}
void solve(){
    cin >> n >> dic + 1;
    init();
    for(int i=1;i<=n;i++) h[i] = -1;
    for(int i=1;i<=n;i++){
        int l,r;
        cin >> l >> r;
        if(l != 0) add(i,l,1),add(l,i,1);
        if(r != 0) add(i,r,2),add(r,i,2);
    }
    dp[1] = 0;
    dfs(1,0);
    int ans = 2e9;
    for(int i=2;i<=n;i++){
        if(ind[i] <= 2) ans = min(ans,dp[i]);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}