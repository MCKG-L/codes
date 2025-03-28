#include <bits/stdc++.h>
using namespace std;
const int N = 1010,INF = 0x3f3f3f3f;
int g[N][N],dist[N];
bool vis[N];
int n,m;
//狄克斯特拉算法
int dijkstra(int start,int end){
    memset(dist,INF,sizeof(dist));
    dist[start] = 0;
    int t = -1;
    for(int j=1;j<=n;j++){
        if(!vis[j] && (t == -1 || dist[t] > dist[j])){
            t = j;
        }
    }
    vis[t] = true;
    for(int k=1;k<=n;k++){
        dist[k] = min(dist[k],dist[t]+g[t][k]);
    }
    return (dist[end]!=INF ? dist[end] : -1);
}
int main()
{
    int a,b,w;
    cin >> n >> m;
    memset(g,INF,sizeof(g));
    for(int i=1;i<=m;i++){
        cin >> a >> b >> w;
        g[a][b] = min(g[a][b],w);
    }

    int value = dijkstra(1,n);
    cout << value;
    return 0;
}