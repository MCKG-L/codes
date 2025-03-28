#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;
const int N = 1e5 + 10,M = 2e5 + 10;
int h[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],siz[N],scc_cnt;
void add(int h[],int a,int b){
    e[idx] = b;
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
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        h[i] = -1;
        scc_cnt = idx = ts = top = 0;
        in_stk[i] = false;
        dfn[i] = low[i] = siz[i] = 0;
    }
    vector<int> a(n + 10);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        if(2 * a[u] >= a[v]) add(h,v,u);
        if(2 * a[v] >= a[u]) add(h,u,v);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    vector<int> din(n + 10);
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            if(a != b) din[b] ++;
        }
    }
    int cnt = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(din[i] == 0) cnt ++;
        if(cnt >= 2){
            cout << 0 << endl;
            return;
        }
    }
    cout << siz[scc_cnt] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}