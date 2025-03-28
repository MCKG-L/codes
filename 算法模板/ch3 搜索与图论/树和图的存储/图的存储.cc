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
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int main()
{
    int n,m;
    cin >> n >> m;
    memset(h,-1,sizeof(h));
    
}