#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#define endl '\n'
#define MAXSIZE 110
#define INF 0x3f3f3f3f
using namespace std;
enum Status{OK = 1,ERROR = 0,OVERFLOE = -1};
typedef int ArcType;
typedef char VertexType;
//邻接矩阵的存储形式
typedef struct{
    VertexType vexs[MAXSIZE];
    ArcType arcs[MAXSIZE][MAXSIZE];
    int vexnum,arcnum;
}AMGraph;
struct CloseEdge{
    VertexType adjvex;  //最小边在U中的顶点序号
    ArcType lowcost;  // 最小边上的权值
} closeEdge[MAXSIZE] ;
/*
5 7
1 2 3 4 5
1 2 1   
1 4 1
2 3 1
2 5 1
3 4 1
3 5 1
4 5 1
*/
int LocateVex(AMGraph G,VertexType v){
    for(int i=0;i<G.vexnum;i++){
        if(G.vexs[i] == v) return i;
    }
    return -1;
}
//创建图
Status CreateUDG_AM(AMGraph &G){
    cout << "请输入点数和边数：";
    cin >> G.vexnum >> G.arcnum;
    //读入点的信息
    cout << "请输入点信息：";
    for(int i=0;i<G.vexnum;i++){
        cin >> G.vexs[i];
    }
    memset(G.arcs,0X3f,sizeof G.arcs);
    //读入边的信息
    cout << "请输入边信息：" << endl;   
    for(int k=0;k<G.arcnum;k++){
        char v1,v2;int w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        // G.arcs[i][j] = G.arcs[j][i] = w;//创建无向图
        G.arcs[i][j] = w;//创建有向图
    }
    return OK;
}
bool st[MAXSIZE];
//DFS
void DFS_AM(AMGraph G,int v){
    cout << G.vexs[v] << ' ';
    st[v] = true;
    for(int i=0;i<G.vexnum;i++){
        if(G.arcs[v][i] != INF && !st[i]) DFS_AM(G,i);
    }
}
void DFSTraverse_AM(AMGraph G){    
    memset(st,false,sizeof st);
    for(int i=0;i<G.vexnum;i++){
        if(!st[i]) DFS_AM(G,i);
    }
    cout << endl;
}
//BFS
void BFS_AM(AMGraph G,int u){
    cout << G.vexs[u] << ' ';
    queue<int> que;
    que.push(u);
    st[u] = true;
    while(que.size()){
        int v = que.front();
        que.pop();
        for(int i=0;i<G.vexnum;i++){
            if(G.arcs[v][i] != INF && !st[i]){
                cout << G.vexs[i] << ' ';
                que.push(i);
                st[i] = true;
            }
        }
    }
}
void BFSTraverse_AM(AMGraph G){
    memset(st,false,sizeof st);
    for(int i=0;i<G.vexnum;i++){
        if(!st[i]) BFS_AM(G,i);
    }
    cout << endl;
}
//Dijkstr算法求单源最短路
/*
6 8
0 1 2 3 4 5
0 2 10
0 4 30
0 5 100
1 2 5
2 3 50
3 5 10
4 5 60
4 3 20
*/
int dis[MAXSIZE],path[MAXSIZE];
void Dijkstra_AM(AMGraph G,int k){
    memset(st,false,sizeof st);//初始化每个点都不在集合中
    for(int i=0;i<G.vexnum;i++){
        dis[i] = G.arcs[k][i];
        if(dis[i] != INF) path[i] = k;
        else path[i] = -1;
    }
    dis[k] = 0;
    int n = G.vexnum;
    for(int i=0;i<n;i++){ 
        int t = -1;
        //选取未在集合中且距离起始点最近的点
        for(int j=0;j<n;j++){
            if(!st[j] && (t == -1 || dis[j] < dis[t])) t = j;
        }
        st[t] = true;
        // cout << "T:" << t << " dis:" << ' ' << dis[t] << endl; 
        //更新其他所有点的距离
        for(int j=0;j<n;j++){
            if(dis[j] > dis[t] + G.arcs[t][j]){
                dis[j] = dis[t] + G.arcs[t][j];
                path[j] = t;
            }
        }
    }
    cout << "最短路径为：";
    stack<int> p;
    int u = n - 1;
    while(u != k){
        p.push(u);
        u = path[u];
    }
    p.push(k);
    while(p.size()){
        cout << G.vexs[p.top()] << ' ';
        p.pop();
    }
    cout << endl;
    cout << "最短路的长度为" << ' ' << dis[n-1] << endl;
}
//找到closeEdge中的最小值
int find(AMGraph G,struct CloseEdge[]){
    int Min = INF;
    VertexType pos;
    for(int i=0;i<G.arcnum;i++){
        if(closeEdge[i].lowcost != 0 && closeEdge[i].lowcost < Min){
            Min = closeEdge[i].lowcost;
            pos = G.vexs[i];
        }
    }
    return LocateVex(G,pos);
}
/*
5 7
1 2 3 4 5
1 2 1   
1 4 1
2 3 1
2 5 1
3 4 1
3 5 1
4 5 1
*/
//最小生成树算法--prim算法
void MiniSpanTree_PRIM_AM (AMGraph G, int k) {
    int weight = 0;//最小生成树的权值
    // int k = LocateVex(G,u);
    for(int j=0;j<G.vexnum;j++){
        if(j != k){
            closeEdge[j].adjvex = G.vexs[k];
            closeEdge[j].lowcost = G.arcs[k][j];    
        }
    }
    cout << "最小生成树的边集为：" << endl;
    closeEdge[k].lowcost = 0;//表示已经在集合中了
    for(int i=1;i<G.vexnum;i++){
        k = find(G,closeEdge);
        //最小生成树的边
        weight += closeEdge[k].lowcost;
        cout << closeEdge[k].adjvex << ' ' << G.vexs[k] << endl; 
        closeEdge[k].lowcost = 0;//在集合U中
        //修改其他结点的信息
        for(int j=0;j<G.arcnum;j++){
            if(G.arcs[k][j] < closeEdge[j].lowcost){
                closeEdge[j].lowcost = G.arcs[k][j];
                closeEdge[j] = { G.vexs[k], G.arcs[k][j]}; 
            }
        }
    }
    cout << "最小生成树的权值为：" << weight << endl;
}
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << "1----创建图" << endl;
    cout << "2----图的深度优先遍历" << endl;
    cout << "3----图的广度优先遍历" << endl;
    cout << "4----求单源最短路" << endl;
    cout << "5----求最小生成树" << endl;
    cout << "0----退出！" << endl;
}
int main()
{
    string op;//读取操作字符串
    show_help();
    /*定义线性表变量，如LinkList L;*/
    AMGraph G;
    cout << "请输入操作码: ";
    while(cin >> op)
    {
        if(op == "1"){
            if(CreateUDG_AM(G)){
                cout << "创建成功！" << endl;
            }else{
                cout << "创建失败！" << endl;
            }

        }else if(op == "2"){
            DFSTraverse_AM(G);
        }else if(op == "3"){
            BFSTraverse_AM(G);
        }else if(op == "4"){
        	Dijkstra_AM(G,0);
		}else if(op == "5"){
            MiniSpanTree_PRIM_AM(G,0);
        }else if(op == "0"){
            cout << "成功退出！" << endl;
            break;
        }else{
            cout << "操作码错误！" << endl;
        }
        cout << "请输入操作码：";
    }
    return 0;
}