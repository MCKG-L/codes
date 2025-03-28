#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10,M = N * 2;
/*
1、tarjan + 缩点
2、在DAG图上做双关键字dp，直接按照拓扑序递推即可
*/
int h[N],ne[M],e[M],w[N],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int siz[N],sum[N];
int id[N],scc_cnt;
int din[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void init(){
    idx = 0;top = 0;
    scc_cnt = 0;
    for(int i=1;i<=n;i++){
        h[i] = -1;
        sum[i] = siz[i] = 0;
        dfn[i] = low[i] = 0;
        id[i] = 0;din[i] = 0;
        in_stk[i] = false;
    }
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
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            siz[scc_cnt] ++;
            sum[scc_cnt] += w[y];
        }while(y != u);
    }
}
void solve(){
    cin >> n >> m;
    init();
    for(int i=1;i<=n;i++) cin >> w[i];
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    vector<vector<int>> dag(scc_cnt+1);
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            if(a != b){
                dag[a].push_back(b);
                din[b] ++;
            }
        }
    }
    vector<int> dp(scc_cnt+10),cnt(scc_cnt+10);
    //按照拓扑序线性求dp
    for(int i=scc_cnt;i>=1;i--){
        if(din[i] == 0){
            cnt[i] = siz[i];
            dp[i] = sum[i];
        }
        for(auto k : dag[i]){
            if(siz[k] + cnt[i] > cnt[k]){
                cnt[k] = cnt[i] + siz[k];
                dp[k] = sum[k] + dp[i];
            }else if(siz[k] + cnt[i] == cnt[k]){
                dp[k] = min(dp[k],dp[i]+sum[k]);
            }
        }
    }
    int mx = 0,ans = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(cnt[i] > mx){
            ans = dp[i];
            mx = cnt[i];
        }else if(cnt[i] == mx && ans > dp[i]){
            ans = dp[i];
        }
    }
    cout << mx << ' ' << ans << endl;
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