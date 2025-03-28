#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
typedef pair<int,int> PII;
const int INF = (1 << 31) - 1;
const int N = 1e4 + 10,M = 5e5 + 10;
int h[N],ne[M],e[M],w[M],idx;
int dis[N];
bool st[N];
int n,m,s;
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void Dijkstra(int s){
    for(int i=1;i<=n;i++) dis[i] = INF;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    dis[s] = 0;
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
    cin >> n >> m >> s;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++){
        cout << dis[i] << ' ';
    }
    return 0;
}