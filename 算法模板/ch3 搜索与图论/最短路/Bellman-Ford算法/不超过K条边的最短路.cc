#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
/*
该题限制了最短路的边数 不超过K条边的最短路径
为了保证使用不超过k条边，需要额外记录上一次循环后dis数组的情况 使用上一次的dis更新最短路径 
循环k次即经过不超过k条边的最短路，可能不能到达终点
*/
const int N = 510,M = 10010;
int n,m,k;
int dis[N],backup[N];
struct E{
    int a,b,w;
}e[M];
int Bellman_ford(){
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    for(int i=0;i<k;i++){
        memcpy(backup,dis,sizeof dis);
        for(int j=0;j<m;j++){
            int a = e[j].a,b = e[j].b,w = e[j].w;
            dis[b] = min(dis[b],backup[a]+w);
        }
    }
    if(dis[n] > 0x3f3f3f3f / 2) return -1;
    //不能到达n点，但是n前面的前可能会到n点，则最后即使从起点不能到达n，dis[n]也可能不等于0x3f3f3f3f;
    return dis[n];
}
int main()
{
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        e[i] = {a,b,w};
    }
    int t = Bellman_ford();
    if(t == -1) cout << "Imposible!" << endl;
    else cout << t << endl;
    return 0;
}