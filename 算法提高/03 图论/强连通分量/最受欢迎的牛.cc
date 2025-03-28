#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1e4 + 10,M = 5e4 + 10,INF = 2e9;
int n,m;
int h[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],scc_cnt,siz[N];
int dout[N];
void add(int a,int b){
    ne[idx] = h[a];
    e[idx] = b;
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
    if(dfn[u] == low[u]){
        scc_cnt ++;
        int y;
        do{
            y = stk[top --];
            in_stk[y] = false;
            id[y] = scc_cnt;//y所属连通分量的编号为scc_cnt
            siz[scc_cnt] ++;
        }while(y != u);
    }
}
void solve(){
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    //build
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0){//没有被遍历过
            tarjan(i);
        }
    }
    //统计所有强联通分量的出度
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            if(a != b){ //不属于同一个强联通分量
                dout[b] ++;
            }
        }
    }
    int cnt = 0,ans = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(dout[i] == 0){ //叶子节点
            cnt ++;
            ans += siz[i];
            if(cnt >= 2){
                ans = 0;
                break;
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}