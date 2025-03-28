#include <iostream>
#include <cstring>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
typedef pair<double,int> PDI;
const int N = 110,M = 2010;
int e[M],h[N],ne[M],idx;
double dis[N],w[M];
bool st[N];
int n,m,s,f;
struct P{
    int x,y;
}p[N];
void add(int a,int b,double d){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = d;
    h[a] = idx++;
}
double Dijkstra(int s){
    for(int i=0;i<N;i++){
        dis[i] = 1e9;
    }
    dis[s] = 0;
    priority_queue<PDI,vector<PDI>,greater<PDI>> heap;
    heap.push({0,s});
    while(heap.size()){
        PDI t = heap.top();heap.pop();
        int k = t.second;
        double d = t.first;
        if(st[k]) continue;
        st[k] = true;
        for(int i=h[k];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > w[i] + d){
                dis[j] = w[i] + d;
                heap.push({dis[j],j});
            }
        }
    }
    return dis[f];
}
// double spfa(int s){
//     // memset(dis,0x3f,sizeof dis);
//     for(int i=0;i<N;i++) dis[i] = 1e9;
//     queue<int> q;
//     q.push(s);
//     dis[s] = 0;st[s] = 1;
//     while(q.size()){
//         int t = q.front();q.pop();
//         st[t] = 0;
//         for(int i=h[t];i!=-1;i=ne[i]){
//             int j = e[i];
//             if(dis[j] > dis[t] + w[i]){
//                 dis[j] = dis[t] + w[i];
//                 if(!st[j]){
//                     q.push(j);
//                     st[j] = 1;
//                 }
//             }
//         }
//     }
//     return dis[f];
// }
int main()
{
    memset(h,-1,sizeof h);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i].x >> p[i].y;
    }
    cin >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        double d = sqrt(pow(p[a].x-p[b].x,2)+pow(p[a].y-p[b].y,2));
        add(a,b,d),add(b,a,d);
    }
    cin >> s >> f;
    cout << fixed << setprecision(2);
    cout << Dijkstra(s) << endl;
    return 0;
}