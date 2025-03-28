#include <iostream>
#include <cstring>
#include <algorithm>
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