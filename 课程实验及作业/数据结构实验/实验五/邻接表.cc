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
int LocateVex(ALGraph G,VertexType v){
    for(int i=0;i<G.vexnum;i++){
        if(G.vertices[i].data == v) return i;
    }
    return -1;
}
//创建图    
Status CreateUDG_AL(ALGraph &G){
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
void DFS_AL(ALGraph G, int v){   //图G为邻接表类型 
    cout << G.vertices[v].data << ' ';
    st[v] = true;   //访问第v个顶点
    ArcNode *p= G.vertices[v].firstarc; //p指向v的边链表的第一个边结点 
    while(p != NULL) //边结点非空 
    {
        int w = p->adjvex;  //表示w是v的邻接点 
        if(!st[w]) DFS_AL(G,w);//如果w未访问，则递归调用DFS 
        p = p->nextarc; //p指向下一个边结点 
    } 
}
void DFSTraverse_AL(ALGraph G){         
    memset(st,false,sizeof st);
    for(int i=0;i<G.vexnum;i++){
        if(!st[i]) DFS_AL(G,i);
    }
    cout << endl;
}
//BFS
void BFS_AL(ALGraph G,int u){
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
void BFSTraverse_AL(ALGraph G){
    memset(st,false,sizeof st);
    for(int i=0;i<G.vexnum;i++){
        if(!st[i]) BFS_AL(G,i);
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
//Dijkstra算法
int dis[MAXSIZE],path[MAXSIZE];
void Dijkstra_AL(ALGraph G,int k){
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
        for(p=G.vertices[t].firstarc;p!=NULL;p=p->nextarc){
            int w = p->adjvex;
            if(dis[w] > dis[t] + p->info.data){
                dis[w] = dis[t] + p->info.data;
                path[w] = t;
            }
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
void MiniSpanTree_PRIM_AL (ALGraph G, int k) {
    int weight = 0;
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
    cout << "最小生成树的边集为：" << endl;
    for(int i=1;i<G.vexnum;i++){
        k = find(G,closeEdge);
        //最小生成树的边
        weight += closeEdge[k].lowcost;
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
    ALGraph G;
    cout << "请输入操作码: ";
    while(cin >> op)
    {
        if(op == "1"){
            if(CreateUDG_AL(G)){
                cout << "创建成功！" << endl;
            }else{
                cout << "创建失败！" << endl;
            }

        }else if(op == "2"){
            DFSTraverse_AL(G);
        }else if(op == "3"){
            BFSTraverse_AL(G);
        }else if(op == "4"){
        	Dijkstra_AL(G,0);
		}else if(op == "5"){
            MiniSpanTree_PRIM_AL(G,0);
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