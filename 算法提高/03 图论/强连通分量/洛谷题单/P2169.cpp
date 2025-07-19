#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10,M = 1e6 + 10;
int h[N],ne[M],e[M],w[M],idx;
int dfn[N],low[N],ts;
int stk[N],top;
bool in_stk[N];
int id[N],scc_cnt;
int dis[N];
bool st[N];
int n,m;
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
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
        int y;scc_cnt ++;
        do {
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
        }while(y != u);
    }
}
void Dijkstra(){
    memset(dis,0x3f,sizeof dis);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    dis[1] = 0;
    while(heap.size()){
        auto [d,k] = heap.top();
        heap.pop();
        if(st[k]) continue;
        st[k] = true;
        for(int i=h[k];~i;i=ne[i]){
            int j = e[i];
            if(id[k] == id[j]) w[i] = 0;
            if(d + w[i] < dis[j]){
                dis[j] = d + w[i];
                heap.push({dis[j],j});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }   
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i);
    }
    Dijkstra();
    cout << dis[n] << endl;
    return 0;
}   