#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
1、初始化距离：dis[1] = 0,dis[i] = 无穷大
2、n次循环，每一次循环在未确定最短距离的点中找到距离最近的点，然后用该点更新所有点的距离

该算法基于贪心算法
朴素Dijkstra算法适用于稠密图 用邻接矩阵存图
*/
//可以处理重边和自环 但是边权必须为正值
/*
6 8
1 2 5
1 3 1
2 3 8
2 4 7
3 4 3
3 6 7
4 5 1
5 6 1
*/
const int N = 1010;
int n,m;
int g[N][N];
int dis[N],prv[N];
bool st[N];//以确定最短距离的点
//距离和最短距离指的是从起点到该点的距离、最短距离
int dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    for(int i=0;i<n;i++){//每次循环都会确定一个点的最小距离
        int t = -1;//为了使第一个点符合条件
        //在未确定最短距离的点中找到离起点最近的点t
        for(int j=1;j<=n;j++){
            if(!st[j] && (t == -1 || dis[t] > dis[j])){
                t = j;
            }
        }
        st[t] = true;//已经确定最短距离的点
        //用t更新最短距离
        for(int j=1;j<=n;j++){
            // dis[j] = min(dis[j],dis[t] + g[t][j]);
            if(dis[j] > dis[t] + g[t][j]){
                dis[j] = dis[t] + g[t][j];
                prv[j] = t;
            }
        }
    }
    if(dis[n] == 0x3f3f3f3f) return -1;//无法到达
    return dis[n];
}
int dj(){
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!st[j] && (t == -1 || dis[j] < dis[t])) t = j;
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
    memset(g,0x3f,sizeof(g));
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b],c);//处理重边，保留最小的边
        g[b][a] = min(g[b][a],c);
    }
    int t = dijkstra();
    for(int i=1;i<=n;i++) cout << prv[i] << ' ';cout << endl;
    cout << t << endl;
    return 0;
}