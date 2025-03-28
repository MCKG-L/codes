#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
图分为无向图和有向图 无向图即为双向建边
有向图的存储：
邻接矩阵 g[a][b] 有权重时值为权重 权重都为1时值为1表示有边，0表示无边
邻接表 就是多个单链表 存储每个点可以到达的所有点
*/
const int N = 100010,M = N * 2;
int h[N],e[N],ne[M],idx;
bool st[N];
int d[N],q[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//dfs遍历
void dfs(int u){
    st[u] = 1;
    for(int i=h[u];i != -1;i = ne[i]){
        int j = e[i];
        if(!st[j]) dfs(j);
    }
}
//bfs遍历
int bfs(){
    int hh = 0,tt = 0;
    q[0] = 1;
    memset(d,-1,sizeof(d));
    d[1] = 0;
    while(hh <= tt){
        int t = q[hh ++];
        for(int i=h[t];i != -1;i = ne[i]){
            int j = e[i];
            if(d[j] == -1){
                d[j] = d[t] + 1;
                q[++ tt] = j;
            }
        }
    }
    return d[n];
}
int main()
{
    memset(d,-1,sizeof d);
    for(int i=0;i<10;i++) cout << d[i] << ' ';
    // cin >> n >> m;
    memset(h,-1,sizeof(h));
    // dfs(1);
    return 0;
}