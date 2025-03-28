#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
/*
多源汇一点的最短路径之和，可以用反向建边的方法 转化为单源最短路径
反向图的技巧 拓展空间 将反向图建在原图的后边
*/
const int N = 2010,M = 2e5+1;
int e[M],w[M],ne[M],h[N],idx;
int dis[N];
bool st[N];
int n,m;
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
void Dijkstra(int s){
    memset(dis,0x3f,sizeof dis);
    memset(st,false,sizeof st);
    dis[s] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,s});
    while(heap.size()){
        PII t = heap.top();heap.pop();
        int k = t.second,d = t.first;
        if(st[k]) continue;
        st[k] = true;
        for(int i=h[k];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > d + w[i]){
                dis[j] = d + w[i];
                heap.push({dis[j],j});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b+n,a+n,c);
    }
    Dijkstra(1);
    long long ans = 0;
    for(int i=1;i<=n;i++) ans += dis[i];
    Dijkstra(1+n);
    for(int i=n+1;i<=n<<1;i++) ans += dis[i];
    cout << ans << endl;
    return 0;
}