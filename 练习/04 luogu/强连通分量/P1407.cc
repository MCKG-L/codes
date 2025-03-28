#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 10000,M = 30010;
int h[N],ne[M],e[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],scc_cnt;
int B[N],G[N];
int n,m;
map<string,int> to;
int now;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void tarjan(int u){
    dfn[u] = low[u] = ++ ts;
    stk[++top] = u;
    in_stk[u] = true;
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
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n;i++){
        string s1,s2;
        cin >> s1 >> s2;
        to[s1] = ++ now;
        to[s2] = ++ now;
        G[i] = to[s1];
        B[i] = to[s2];
        add(G[i],B[i]);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        string s1,s2;
        cin >> s1 >> s2;
        add(to[s2],to[s1]);
    }
    for(int i=1;i<=2*n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    for(int i=0;i<n;i++){
        // cout << id[G[i]] << ' ' << id[B[i]] << endl;
        int a = id[B[i]],b = id[G[i]];
        if(a == b){
            cout << "Unsafe" << endl;
        }else{
            cout << "Safe" << endl;
        }
    }
    return 0;
}