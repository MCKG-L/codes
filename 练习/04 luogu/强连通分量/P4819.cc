#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10,M = 1e6 + 10,INF = 0x3f3f3f3f;
int h[N],hs[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],siz[N],scc_cnt;
int din[N],dout[N];
int n,m;
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
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        add(h,a,b);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    unordered_set<int> st;
    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i],b = id[k];
            int hash = a * N + b;
            if(a != b && st.count(hash) == 0){
                din[b] ++,dout[a] ++;
                add(hs,a,b);
                st.insert(hash);
            }
        }
    }
    int cnt = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(din[i] == 0) cnt ++;
    }
    bool ok = 0;
    for(int i=1;i<=scc_cnt;i++){
        if(din[i] == 0 && siz[i] == 1){
            bool f = 1;
            for(int j=hs[i];~j;j=ne[j]){
                int k = e[j];
                if(din[k] <= 1){
                    f = 0;break;
                }
            }
            if(f){
                ok = 1;break;
            }
        }
    }
    if(ok) cnt --;
    //cout << fixed << setprecision(6) << (n-cnt)*1.0/n << endl;
    printf("%.6f\n",(n-cnt)*1.0/n);
    return 0;
}