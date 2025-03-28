#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10010;
int g[N][N];
int dis[N];
bool st[N];
int n,m;
int Dijkstra(){
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!st[j] && (t == -1 || dis[j] < dis[t])){
                t = j;
            }
        }
        st[t] = true;
        for(int j=1;j<=n;j++){
            dis[j] = min(dis[j],dis[t] + g[t][j]);
        }
    }
    if(dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
}
int main()
{
    cin >> n >> m;
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b],c);
    }
    int t = Dijkstra();
    if(t == -1) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}