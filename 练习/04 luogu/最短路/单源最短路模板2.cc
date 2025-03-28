#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,M = 2e5 + 10;
int h[N],e[M],w[M],ne[M],idx;
int dis[N];
bool st[N];
int n,m,s;
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
void spfa(int s){
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0;
    queue<int> que;
    que.push(s);st[s] = 1;
    while(que.size()){
        int k = que.front();que.pop();
        st[k] = 0;
        for(int i=h[k];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > dis[k] + w[i]){
                dis[j] = dis[k] + w[i];
                if(!st[j]) que.push(j),st[j] = 1;
            }
        }
    }

}
void Dijkstra(int s){
    memset(dis,0x3f,sizeof dis);
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
    memset(h,-1,sizeof dis);
    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    Dijkstra(s);
    // spfa(s);
    for(int i=1;i<=n;i++) cout << dis[i] << ' ';
    cout << endl;
    return 0;
}