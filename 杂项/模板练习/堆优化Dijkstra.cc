#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 10010;
int e[N],ne[N],h[N],w[N],idx;
int dis[N];
bool st[N];
int n,m;
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
int Dijkstra(){
    memset(dis,0x3f,sizeof dis);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push(make_pair(0,1));
    dis[1] = 0;
    while(heap.size()){
        PII t = heap.top();heap.pop();
        int k = t.second,d = t.first;
        if(st[k]) continue;
        st[k] = true;//每一次可以确定堆顶点的最小距离
        for(int i=h[k];i!=-1;i=ne[i]){//枚举点k的所有出边
            int j = e[i];
            if(dis[j] > w[i] + d){//注意是w[i]而不是w[j]
                dis[j] = w[i] + d;
                heap.push(make_pair(dis[j],j));
            }
        }
    }
    if(dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    int t = Dijkstra();
    if(t == -1) puts("impossible");
    else cout << t << endl;
    return 0;
}