#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
using namespace std;
const int N = 20010,M = 20010,INF = 0x3f3f3f3f;
int h[N],hs[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],siz[N],scc_cnt;
int n,m;
int w[N],c[N],din[N];
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
            siz[scc_cnt] ++;
        }while(y != u);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    memset(h,-1,sizeof h);
    memset(hs,-1,sizeof hs);
    memset(c,0x3f,sizeof c);
    memset(w,0x3f,sizeof w);
    for(int i=0;i<m;i++){
        int k,x;
        cin >> k >> x;
        c[k] = x;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        add(h,a,b);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        int a = id[i];
        w[a] = min(w[a],c[i]);
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int b = id[k];
            if(a != b){
                add(hs,a,b);
                din[b] ++;
            }
        }
    }
    vector<int> all[scc_cnt+1];
    int p = 1e9;bool f = 1;
    for(int i=1;i<=n;i++){
        int k = id[i];
        all[k].push_back(i);
    }
    queue<int> q;
    vector<bool> st(n+1);
    for(int i=1;i<=scc_cnt;i++){
        if(w[i] == INF && din[i] == 0) q.push(i),st[i] = 1,f = 0;
    }
    while(q.size()){
        auto k = q.front();q.pop();
        for(int i=hs[k];~i;i=ne[i]){
            int j = e[i];
            if(c[j] == INF) p = min(p,j);
            if(!st[j]) q.push(j),st[j] = 1;
        }
    }
    if(!f) cout << "NO\n" << p << endl;
    else{
        int ans = 0;
        for(int i=1;i<=scc_cnt;i++){
            if(din[i] == 0) ans += w[i];
        }
        cout << "YES\n" << ans << endl;
    }
    return 0;
}