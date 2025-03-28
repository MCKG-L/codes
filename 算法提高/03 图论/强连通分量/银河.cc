#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,M = 6e5 + 10;
int h[N],hs[N],ne[M],e[M],w[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],siz[N],scc_cnt;
int dis[N];
int n,m;
void add(int h[],int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void tarjan(int u){
    dfn[u] = low[u] = ++ ts;
    stk[++top] = u;in_stk[u] = true;
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(dfn[j] == 0){
            tarjan(j);
            low[u] = min(low[u],low[j]);
        }else if(in_stk[j]) low[u] = min(low[u],dfn[j]);
    }
    if(dfn[u] == low[u]){
        scc_cnt ++;
        int y;
        do {
            y = stk[top --];
            in_stk[y] = false;
            id[y] = scc_cnt;
            siz[scc_cnt] ++;
        }while(y != u);
    }
}
void solve(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    memset(hs,-1,sizeof hs);
    for(int i=0;i<m;i++){
        int t,a,b;
        cin >> t >> a >> b;
        if(t == 1) add(h,a,b,0),add(h,b,a,0);
        else if(t == 2) add(h,a,b,1);
        else if(t == 3) add(h,b,a,0);
        else if(t == 4) add(h,b,a,1);
        else add(h,a,b,0);
    }
    for(int i=1;i<=n;i++) add(h,0,i,1);
    tarjan(0);
    bool ok = 1;
    for(int i=0;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            if(a == b){
                if(w[j] > 0){
                    ok = false;break;
                }
            }else add(hs,a,b,w[j]);
        }
        if(!ok) break;
    }
    if(ok == 0){
        cout << -1 << endl;
        return;
    }
    for(int i=scc_cnt;i>=1;i--){
        for(int j=hs[i];~j;j=ne[j]){
            int k = e[j];
            dis[k] = max(dis[k],dis[i]+w[j]);
        }
    }
    int ans = 0;
    for(int i=1;i<=scc_cnt;i++){
        ans += dis[i] * siz[i];
    }
    cout << ans << endl;
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