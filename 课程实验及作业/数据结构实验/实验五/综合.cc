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

//邻接表的存储形式
struct OtherInfo{
    int data;
};
typedef struct ArcNode{ //边结构
    int adjvex;//该边指向的顶点位置
    struct ArcNode *nextarc;//指向下一条边的指针
    OtherInfo info;
}ArcNode;
typedef struct VNode{ //点结构
    VertexType data;
    ArcNode *firstarc;
}VNode,AdjList[MAXSIZE];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;

int LocateVex(AMGraph G,VertexType v){
    for(int i=0;i<G.vexnum;i++){
        if(G.vexs[i] == v) return i;
    }
    return -1;
}
int LocateVex(ALGraph G,VertexType v){
    for(int i=0;i<G.vexnum;i++){
        if(G.vertices[i].data == v) return i;
    }
    return -1;
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
Status CreateUDN(AMGraph &G){
    cout << "请输入点数和边数：";
    cin >> G.vexnum >> G.arcnum;
    //读入点的信息
    cout << "请输入点信息：";
    for(int i=0;i<G.vexnum;i++){
        cin >> G.vexs[i];
    }
    memset(G.arcs,0X3f,sizeof G.arcs);
    //读入边的信息
    cout << "请输入边信息：";
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
Status CreateUDG(ALGraph &G){
    cout << "请输入点数和边数：";
    cin >> G.vexnum >> G.arcnum;
    //构造头节点表
    cout << "请输入点信息：";
    for(int i=0;i<G.vexnum;i++){
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    //输入边
    cout << "请输入边信息：";
    ArcNode *p1,*p2;
    for(int k=0;k<G.arcnum;k++){
        VertexType v1,v2;
        int w;
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G,v1),j = LocateVex(G,v2); 
        //将p1插入v1的边表中
        p1 = new ArcNode; //p1: v1 --> v2
        p1->adjvex = j;
        p1->info.data = w;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;

        //将p2插入v2的边表中
        p2 = new ArcNode; //p2: v2 --> v1
        p2->adjvex = i;
        p2->info.data = w;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
    return OK;
}
bool st[MAXSIZE];
//DFS
void DFS(AMGraph G,int v){
    cout << G.vexs[v] << ' ';
    st[v] = true;
    for(int i=0;i<G.vexnum;i++){
        if(G.arcs[v][i] != INF && !st[i]) DFS(G,i);
    }
}
void DFS(ALGraph G, int v){   //图G为邻接表类型 
    cout << G.vertices[v].data << ' ';
    st[v] = true;   //访问第v个顶点
    ArcNode *p= G.vertices[v].firstarc; //p指向v的边链表的第一个边结点 
    while(p != NULL) //边结点非空 
    {
        int w = p->adjvex;  //表示w是v的邻接点 
        if(!st[w]) DFS(G,w);//如果w未访问，则递归调用DFS 
        p = p->nextarc; //p指向下一个边结点 
    } 
}
void DFSTraverse(ALGraph G){         
    memset(st,false,sizeof st);
    for(int i=0;i<G.vexnum;i++){
        if(!st[i]) DFS(G,i);
    }
    cout << endl;
}
void DFSTraverse_AM(AMGraph G){    
    memset(st,false,sizeof st);
    for(int i=0;i<G.vexnum;i++){
        if(!st[i]) DFS(G,i);
    }
    cout << endl;
}
//BFS
void BFS(AMGraph G,int u){
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
void BFS(ALGraph G,int u){
    cout << G.vertices[u].data << ' ';
    queue<int> que;
    que.push(u);
    st[u] = true;
    while(que.size()){
        int v = que.front();
        que.pop();
        ArcNode *p = G.vertices[v].firstarc;//v的边链表的首元结点
        while(p != NULL){
            int w = p->adjvex;//该边指向的点位置
            if(!st[w]){
                cout << G.vertices[w].data << ' ';
                que.push(w);
                st[w] = true;
            }
            p = p->nextarc;
        }
    }
}
void BFSTraverse(ALGraph G){
    memset(st,false,sizeof st);
    for(int i=0;i<G.vexnum;i++){
        if(!st[i]) BFS(G,i);
    }
    cout << endl;
}
void BFSTraverse(AMGraph G){
    memset(st,false,sizeof st);
    for(int i=0;i<G.vexnum;i++){
        if(!st[i]) BFS(G,i);
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
void Dijkstra(AMGraph G,int k){
    // int ST = LocateVex(G,s);
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
                // st[j] = true;
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
void Dijkstra(ALGraph G,int k){
    // int ST = LocateVex(G,s);
    memset(st,false,sizeof st);//初始化每个点都不在集合中
    for(int i=0;i<G.vexnum;i++){
        dis[i] = INF;
        path[i] = -1;
    }
    ArcNode *p = G.vertices[k].firstarc;
    while(p != NULL){
        int w = p->adjvex;
        dis[w] = p->info.data;//权值
        path[w] = k;
        p = p->nextarc;
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
        p = G.vertices[t].firstarc;
        while(p != NULL){
            int w = p->adjvex;
            if(dis[w] > dis[t] + p->info.data){
                dis[w] = dis[t] + p->info.data;
                path[w] = t;
            }
            p = p->nextarc;
        }
    }
    cout << "最短路径为：";
    stack<int> stack;
    int u = n - 1;
    while(u != k){
        stack.push(u);
        u = path[u];
    }
    stack.push(k);
    while(stack.size()){
        cout << G.vertices[stack.top()].data << ' ';
        stack.pop();
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
int find(ALGraph G,struct CloseEdge[]){
    int Min = INF;
    VertexType pos;
    for(int i=0;i<G.arcnum;i++){
        if(closeEdge[i].lowcost != 0 && closeEdge[i].lowcost < Min){
            Min = closeEdge[i].lowcost;
            pos = G.vertices[i].data;
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
void MiniSpanTree_PRIM (AMGraph G, int k) {
    // int k = LocateVex(G,u);
    for(int j=0;j<G.vexnum;j++){
        if(j != k){
            closeEdge[j].adjvex = G.vexs[k];
            closeEdge[j].lowcost = G.arcs[k][j];    
        }
    }
    closeEdge[k].lowcost = 0;//表示已经在集合中了
    for(int i=1;i<G.vexnum;i++){
        k = find(G,closeEdge);
        //最小生成树的边
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
}
void MiniSpanTree_PRIM(ALGraph G, int k) {
    for(int i=0;i<G.vexnum;i++){
        if(i != k) {
            closeEdge[i].adjvex = G.vertices[k].data;
            closeEdge[i].lowcost = INF;
        }
    }
    ArcNode *p = G.vertices[k].firstarc;
    while(p != NULL){
        int v = p->adjvex;
        closeEdge[v].lowcost = p->info.data;
        p = p->nextarc;
    }
    closeEdge[k].lowcost = 0;//表示已经在集合中了
    for(int i=1;i<G.vexnum;i++){
        k = find(G,closeEdge);
        //最小生成树的边
        cout << closeEdge[k].adjvex << ' ' << G.vertices[k].data << endl; 
        closeEdge[k].lowcost = 0;//在集合U中
        ArcNode *p = G.vertices[k].firstarc;
        while(p != NULL){
            int w = p->adjvex;
            if(closeEdge[w].lowcost > p->info.data){
                closeEdge[w].lowcost = p->info.data;
                closeEdge[w].adjvex = G.vertices[k].data;
            }
            p = p->nextarc;
        }
    }
}
int main()
{
    ALGraph G;
    CreateUDG(G);
    cout << "深度优先遍历：";
    DFSTraverse(G);
    cout << "广度优先遍历：";
    BFSTraverse(G);
    Dijkstra(G,0);
    MiniSpanTree_PRIM(G,0);
    return 0;
}