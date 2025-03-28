#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
/*
多源汇一点的最短路径之和，可以用反向建边的方法 转化为单源最短路径
*/
const int N = 1010,M = 1e5+10;
int e1[M],ne1[M],h1[N],w1[M],idx1;//正向图
int e2[M],ne2[M],h2[N],w2[M],idx2;//反向图
int dis[N];
bool st[N];
int n,m;
void add(int a,int b,int c){
    e1[idx1] = b;
    w1[idx1] = c;
    ne1[idx1] = h1[a];
    h1[a] = idx1++;
    //反向建边
    e2[idx2] = a;
    w2[idx2] = c;
    ne2[idx2] = h2[b];
    h2[b] = idx2++;
}
void Dijkstra(int *e,int *ne,int *h,int *w){
    memset(dis,0x3f,sizeof dis);
    memset(st,false,sizeof st);
    dis[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
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
    memset(h1,-1,sizeof h1);
    memset(h2,-1,sizeof h2);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    Dijkstra(e1,ne1,h1,w1);
    long long ans = 0;
    for(int i=1;i<=n;i++) ans += dis[i];
    Dijkstra(e2,ne2,h2,w2);
    for(int i=1;i<=n;i++) ans += dis[i];
    cout << ans << endl;
    return 0;
}