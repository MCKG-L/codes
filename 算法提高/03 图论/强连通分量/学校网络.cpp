#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 110,M = 10010;
int n;
int h[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int din[N],dout[N];
int id[N],scc_cnt;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void tarjan(int u){
    dfn[u] = low[u] = ++ ts;
    stk[++top] = u,in_stk[u] = true;
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(dfn[j] == 0){
            tarjan(j);
            low[u] = min(low[u],low[j]);
        }else if(in_stk[j]) low[u] = min(low[u],dfn[j]);
    }
    if(low[u] == dfn[u]){
        scc_cnt ++;
        int y;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
        }while(y != u);
    }
}
void solve(){
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int t;
        while(cin >> t, t) add(i,t);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            if(a != b){
                dout[a] ++;din[b] ++;
            }
        }
    }
    int cnt1 = 0,cnt2 = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(din[i] == 0) cnt1 ++;
        if(dout[i] == 0) cnt2 ++;
    }
    cout << cnt1 << endl;
    if(scc_cnt == 1) cout << 0 << endl;
    else cout << max(cnt1,cnt2) << endl;
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