#include <bits/stdc++.h>
using namespace std;
const int N = 210,M = 1e5 + 10;
int h[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],scc_cnt;
int din[N];
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
int n,m;
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
        int y;scc_cnt ++;
        do {
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
        }while(y != u);
    }
}
int main()
{
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int x;
        while(cin >> x , x) add(i,x);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            if(a != b){
                din[b] ++;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(din[i] == 0) ans ++;
    }
    cout << ans << endl;
}