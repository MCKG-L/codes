#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
有向无环图一定存在拓扑序列 因此有向无环图又称为拓扑图
拓扑序列：将一个有向无环图G进行拓扑排序，是将G中的所有顶点排成一个线性序列
是的图中任意一对顶点(u,v)若边(u,v)属于G的边，则u在线性序列中出现在v之前

入度：指向自己的点数
出度：自己指向其他点的数目
*/
const int N = 100010;
int n,m;
int e[N],h[N],ne[N],idx;
int q[N],d[N];
//d存储的是点的入度
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool topsort(){
    int hh = 0,tt = -1;//如果是有环图，则tt为-1
    //先把所有入度为0的点放入队列中
    for(int i=1;i<=n;i++){
        if(!d[i]) q[++ tt] = i;
    }
    while(hh <= tt){
        int t = q[hh ++];
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            d[j] --;
            if(d[j] == 0) q[++ tt] = j;
        }
    }
    return tt == n-1;
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof(h));
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        add(a,b);
        d[b] ++;
    }
    if(topsort()){
        for(int i=0;i<n;i++) cout << q[i] << ' ';
        cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}