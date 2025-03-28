#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
/*
注意本题不是求路径的最短路，而是求修建道路的最小值，所以没有损坏的道路，权值为0
损坏的道路权值为道路长度，然后从A开始跑一遍最短路，即可求出A到B的修建道路的最小值
*/
typedef pair<int,int> PII;
const int N = 110,M = 5000;
int e[M],ne[M],h[N],w[M],idx;
int dis[N];
int n,m,d;
bool st[N];
bool broken[N][N];
struct P{
    int a,b,c;
}ei[M];
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
void Dijkstra(int s){
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push(make_pair(0,s));
    while(heap.size()){
        PII t = heap.top();heap.pop();
        int k = t.second,di = t.first;
        if(st[k]) continue;
        st[k] = true;
        for(int i=h[k];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > di + w[i]){
                dis[j] = di + w[i];
                heap.push(make_pair(dis[j],j));
            }
        }
    }
}
void spfa(int s){
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0;st[s] = 1;
    queue<int> q;q.push(s);
    while(q.size()){
        int t = q.front();q.pop();
        st[t] = 0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){
                dis[j] = dis[t] + w[i];
                if(!st[j]) q.push(j),st[j] = 1;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        ei[i] = {a,b,c};
    }
    cin >> d;
    while(d--){
        int a,b;
        cin >> a >> b;
        broken[a][b] = broken[b][a] = 1;
    }
    for(int i=0;i<m;i++){
        int a = ei[i].a,b=ei[i].b,c=ei[i].c;
        if(!broken[a][b]) c = 0;
        add(a,b,c),add(b,a,c);
    }
    int A,B;
    cin >> A >> B;
    // Dijkstra(A);
    spfa(A);
    cout << dis[B] << endl;
    return 0;
}