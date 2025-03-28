#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10,M = 1e5;
int h[N],ne[M],e[M],idx;
int stk[N],top;
bool in_stk[N];
int id[N],scc_cnt,siz[N];
int dfn[N],low[N],ts;
int n,m;
void add(int a,int b){
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
            siz[scc_cnt] ++;
        }while(y != u);
    }
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    int ans = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(siz[i] > 1) ans ++;
    }
    cout << ans << endl;
}