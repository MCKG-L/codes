#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5+10,M = 2e5+10;
int h[N],ne[M],e[M],w[M],idx;
int dis[N];
bool st[N];
int n,m,s;
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
void Dijkstra(int s){
    memset(dis,0x3f,sizeof dis);
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push(make_pair(0,s));
    dis[s] = 0;
    while(heap.size()){
        PII t = heap.top();heap.pop();
        int d = t.first,k = t.second;
        if(st[k]) continue;
        st[k] = true;
        for(int i=h[k];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > d + w[i]){
                dis[j] = d + w[i];
                heap.push(make_pair(dis[j],j));
            }
        }
    }
    
}
int main()
{
    memset(h,-1,sizeof h);
    cin >> n >> m >> s;
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