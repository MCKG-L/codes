#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
/*
Bellman-Ford算法适用情况：
1、单源最短路径问题
2、有边数限制的最短路问题 加入一个backup数组存储上次松弛后的dis状态
3、边权存在负数的单源最短路问题
4、可以判断是否含有负环
*/

/*
该算法对存边没有要求，保证能够遍历到所有边即可，所以可以直接用结构体存边
图中如果存在负权回路，则可能没有最短路径
该算法可以判断是否存在负权回路
*/
const int N = 510,M = 10010;
int n,m;
int dis[N];
struct E{
    int a,b,w;
}e[M];
int Bellman_ford(){
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    for(int i=0;i<n-1;i++){//最多进行n-1次松弛操作
        bool flag = 0;
        for(int j=0;j<m;j++){
            int a = e[j].a,b = e[j].b,w = e[j].w;
            if(dis[b] > dis[a] + w){
                dis[b] = min(dis[b],dis[a]+w);
                flag = 1;
            }
        }
        if(!flag) break;
    }
    if(dis[n] > 0x3f3f3f3f / 2) return -1;
    //不能到达n点，但是n前面的前可能会到n点，则最后即使从起点不能到达n，dis[n]也可能不等于0x3f3f3f3f;
    return dis[n];
}
int main()
{
    cin >> n >> m;
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