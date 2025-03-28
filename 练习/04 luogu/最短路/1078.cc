#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 110,M = 10010;
int e[M],h[N],ne[M],w[M],idx;
int a[N][N];
int C[N],pre[N],dis[N];
bool st[N];
int n,m,K,S,T;
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
bool func(int u,int v){
    while(u){
        if(a[C[v]][C[u]]!=0 || C[v] == C[u]){
            return false;
        }
        u = pre[u];
    }
    return true;
}
void Dijkstra(int S){
    memset(dis,0x3f,sizeof dis);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    dis[S] = 0;
    heap.push({0,S});
    while(heap.size()){
        PII t = heap.top();heap.pop();
        int k = t.second,d = t.first;
        if(st[k]) continue;
        st[k] = true;
        for(int i=h[k];i!=-1;i=ne[i]){
            int j = e[i];
            if(func(k,j) && dis[j] > d + w[i]){
                pre[j] = k;
                dis[j] = d + w[i];
                heap.push({dis[j],j});
            }
        }
    }
}
int main()
{
    cin >> n >> K >> m >> S >> T;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) cin >> C[i];
    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++){
            cin >> a[i][j];
        }
    }
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c),add(b,a,c);
    }
    Dijkstra(S);
    if(dis[T] == 0x3f3f3f3f){
        cout << -1 << endl;
        return 0;
    }
    cout << dis[T] << endl;
    return 0;
}