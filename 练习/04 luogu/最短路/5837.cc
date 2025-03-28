#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> PII;
const int N = 1010,M = 2010;
int e[M],h[N],ne[M],w[M],f[M],idx;
int dis[N];
int C[M];
bool st[N];
int n,m;
int ans;
void add(int a,int b,int c,int d){
    e[idx] = b;
    w[idx] = c;
    f[idx] = d;
    ne[idx] = h[a];
    h[a] = idx++;
}
void Dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(st,false,sizeof st);
    dis[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;//小根堆 first存距离 因为默认按照pair的第一个元素排序
    heap.push({0,1});
    while(heap.size()){
        PII t = heap.top();heap.pop();//取出最小距离的点 堆顶元素（小根堆）
        int ver = t.second,distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j = e[i];
            if(f[i] < s) continue;
            if(dis[j] > distance + w[i]){
                dis[j] = distance + w[i];
                heap.push({dis[j],j});//把有距离更新的点放入队列
            }
        }
    }
    if(dis[n] != 0x3f3f3f3f) ans = max(ans,s*1000000/dis[n]);
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    int i = 0;
    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        C[i] = d;
        add(a,b,c,d),add(b,a,c,d);
    }
    for(int i=1;i<=1000;i++) Dijkstra(C[i]);
    cout << ans << endl;
    return 0;
}
