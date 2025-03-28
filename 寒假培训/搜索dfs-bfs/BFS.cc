#include <bits/stdc++.h>
using namespace std;
const int N = 1010,M = 10010;
int e[M],nex[M],h[N],id;
bool istrue[N];
void add(int a,int b){
    e[id] = b;
    nex[id] = h[a];
    h[a] = id++;
}
/*
6 9
1 2
1 3
1 4
2 5
3 4
3 5
3 6
4 6
5 6
*/
// void bfs(int u){
//     int que[N],f=0,t=0;
//     que[++t] = u;
//     istrue[u] = true;
//     cout << u << "出发的广度搜索：";
//     while(f < t){
//         int k = que[++f];
//         cout << "->" << k;

//         //扫描[k]链表
//         for(int i=h[k];i!=-1;i=nex[i]){
//             int j = e[i];
//             if(!istrue[j]){
//                 istrue[j] = true;
//                 que[++t] = j;
//             }
//         }
//     }
// }
//队列做法
queue<int> que;
void bfs(int u){
    que.push(u);//初始条件入队
    istrue[u] = true;
    while(!que.empty()){
        int k = que.front();//调用队首
        que.pop();//队首出队 移除
        cout << "->" << k;
        for(int i=h[k];i!=-1;i=nex[i]){
            int j = e[i];
            if(!istrue[j]){
                istrue[j] = true;
                que.push(j);
            }
        }
    }
}
int main()
{
    int n,m;
    memset(h,-1,sizeof(h));
    cout << "输入点数和边数：" << endl;
    cin >> n >> m;
    cout << "输入起点和终点的值：" << endl;
    for(int i=1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        add(a,b);
        add(b,a); //加上则为无向图，双向边
    }
    bfs(1);
    return 0;
}