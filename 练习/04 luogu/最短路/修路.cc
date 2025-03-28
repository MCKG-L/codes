#include <iostream>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> PII;
const int N = 110,M = 10010;
int h[N],ne[M],e[M],w[M],idx;
int dis[N],bk[N][N];
int d[N][N];
bool st[N];
int n,m,A,B;
struct Node{
    int a,b,c;
}p[M];
void add(int a,int b,int c){
    w[idx] = c;
    ne[idx] = h[a];
    e[idx] = b;
    h[a] = idx ++;
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j] = min(d[i][k]+d[k][j],d[i][j]);
            }
        }
    }
}
void spfa(int s){
    memset(dis,0x3f,sizeof dis);
    dis[s] = 0;st[s] = 1;
    queue<int> que;que.push({s});
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
void Dijkstra(int A){
    memset(dis,0x3f,sizeof dis);
    dis[A] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,A});
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
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) d[i][j] = 1;
            else d[i][j] = INF;
        }
    }
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        cin >> p[i].a >> p[i].b >> p[i].c;
    }
    int dd;cin >> dd;
    while(dd--){
        int a,b;
        cin >> a >> b;
        bk[a][b] = bk[b][a] = 1;
    }
    for(int i=0;i<m;i++){
        int a = p[i].a,b = p[i].b,c = p[i].c;
        if(!bk[a][b]){
            c = 0;
        }
        d[a][b] = d[b][a] = c;
        add(a,b,c),add(b,a,c);
    }
    cin >> A >> B;
    // Dijkstra(A);
    // spfa(A);
    floyd();
    cout << d[A][B] << endl;
    // cout << dis[B] << endl;
    return 0;
}