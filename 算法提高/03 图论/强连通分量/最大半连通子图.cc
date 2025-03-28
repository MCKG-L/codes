#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5+ 10,M = 2e6 + 10,INF = 1e9;
int n,m,x;
int h[N],hs[N],ne[M],e[M],idx;
int dfn[N],low[M],ts;
int stk[N],top;
bool in_stk[N];
int id[N],scc_cnt;
int siz[N];
int f[N],g[N];
void add(int h[],int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void tarjan(int u){
    low[u] = dfn[u] = ++ ts;
    in_stk[u] = true;
    stk[++top] = u;
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(dfn[j] == 0){
            tarjan(j);
            low[u] = min(low[u],low[j]);
        }else if(in_stk[j]) low[u] = min(low[u],dfn[j]);
    }
    if(low[u] == dfn[u]){
        int y;
        scc_cnt ++;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            siz[scc_cnt] ++;
        }while(u != y);
    }
}
void solve(){
    cin >> n >> m >> x;
    memset(h,-1,sizeof h);
    memset(hs,-1,sizeof hs);
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        add(h,a,b);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    unordered_set<int> st;
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            int hash = a * INF + b;
            if(a != b && st.count(hash) == 0){
                add(hs,a,b);
                st.insert(hash);
            }
        }
    }
    //tarjan节点编号就是逆拓扑序
    for(int i=scc_cnt;i>=1;i--){
        if(f[i] == 0){
            f[i] = siz[i];
            g[i] = 1;
        }
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            if(f[k] < f[i] + siz[k]){
                f[k] = f[i] + siz[k];
                g[k] = g[i];
            }else if(f[k] == f[i] + siz[k]){
                g[k] = (g[k] + g[i]) % x;
            }
        }
    }
    int mx = -1,ans = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(f[i] > mx){
            mx = f[i];
            ans = g[i];
        }else if(f[i] == mx){
            ans = (ans + g[i]) % x;
        }
    }
    cout << mx << '\n' << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}