#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef pair<int,int> PII;
const int N = 1e4+10,M = 5e5+10,INF = pow(2,31)-1;
int h[N],e[M],ne[M],w[M],idx;
int dis[N];
bool st[N];
int n,m,s;
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
        int k = t.second,d = t.first;
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
    cin >> n >> m >> s;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++){
        if(dis[i] == 0x3f3f3f3f) cout << INF << ' ';
        else cout << dis[i] << ' ';
    }
    cout << endl;
    return 0;
}