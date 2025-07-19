#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10,M = 3e5 + 10,INF = 0x3f3f3f3f;
int h[N],hs[N],w[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],siz[N],cost[N],scc_cnt;
int f[N],g[N];
int n,m;
void add(int h[],int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void tarjan(int u){
    low[u] = dfn[u] = ++ ts;
    stk[++top] = u;in_stk[u] = true;
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(dfn[j] == 0){
            tarjan(j);
            low[u] = min(low[u],low[j]);
        }else if(in_stk[j]) low[u] = min(low[u],dfn[j]);
    }
    if(dfn[u] == low[u]){
        int y;scc_cnt ++;
        do {
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
        }while(y != u);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    memset(h,-1,sizeof h);
    memset(cost,0x3f,sizeof cost);
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++) cin >> w[i];
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        add(h,a,b);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        int k = id[i];
        if(cost[k] > w[i]){
            cost[k] = w[i];
            siz[k] = 1;
        }else if(cost[k] == w[i]) siz[k] ++;
    }
    int cnt = 1,mod = 1e9 + 7,ans = 0;
    for(int i=1;i<=scc_cnt;i++){
        cnt = cnt * siz[i] % mod;
        ans += cost[i];
    }
    cout << ans << ' ' << cnt << endl;
    return 0;
}