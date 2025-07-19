#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10,M = 3e5 + 10;
int h[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],scc_cnt,siz[N];
int din[N],dout[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void tarjan(int u){
    dfn[u] = low[u] = ++ ts;
    stk[++ top] = u;in_stk[u] = true;
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(dfn[j] == 0){
            tarjan(j);
            low[u] = min(low[u],low[j]);
        }else if(in_stk[j]) low[u] = min(low[u],dfn[j]);
    }
    if(dfn[u] == low[u]){
        int y;
        scc_cnt ++;
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
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            if(a != b){
                din[b] ++,dout[a] ++;
            }
        }
    }
    int cnt1 = 0,cnt2 = 0;
    int mx = 1;
    for(int i=1;i<=scc_cnt;i++){
        mx = max(mx,siz[i]);
        if(din[i] == 0) cnt1 ++;
        if(dout[i] == 0) cnt2 ++;
    }
    cout << mx << endl;
    if(scc_cnt == 1){
        cout << 0 << endl;
    }else{
        cout << max(cnt1,cnt2) << endl;
    }
    return 0;
}