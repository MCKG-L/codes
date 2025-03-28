#include <bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using namespace std;
const int N = 1e5 + 10,M = 1e5 + 10;
int h[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int siz[N],id[N],scc_cnt;
int dout[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void tarjan(int u){
    dfn[u] = low[u] = ++ ts;
    stk[++ top] = u,in_stk[u] = true;
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
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            siz[scc_cnt] ++;
        }while(y != u);
    }
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) h[i] = -1;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            if(a != b) dout[a] ++;
        }
    }
    int cnt = 0,ans = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(dout[i] == 0){
            cnt ++;
            ans += siz[i];
            if(cnt >= 2){
                ans = 0;break;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}