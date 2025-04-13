#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 510,INF = 0x3f3f3f3f;
int g[N][N];
int n,m;
int dis[N];
bool st[N];
/**
 
和Dijkstra算法的思路类似，不同点是prim算法维护的是到集合S的最短距离
 */
int prim(){
    memset(dis,0x3f,sizeof dis);
    int res = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!st[j] && (t == -1 || dis[t] > dis[j])){
                t = j;
            }
        }
        st[t] = 1;
        if(i && dis[t] == INF) return INF;
        if(i) res += dis[t];//先累加后更新 防止负环影响结果
        for(int j=1;j<=n;j++) dis[j] = min(dis[j],g[t][j]);
    }
    return res;
}
int main()
{
    cin >> n >> m;
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b],c);
    }
    int t = prim();
    if(t == INF) cout << "impossible!" << endl;
    else cout << t << endl;
    return 0;
}