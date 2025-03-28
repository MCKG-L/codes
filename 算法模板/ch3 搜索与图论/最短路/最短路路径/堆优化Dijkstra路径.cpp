#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
const int N = 100010;
int n,m;
int e[N],h[N],ne[N],w[N],idx;
int dis[N],prv[N];
bool st[N];
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
int dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size()){
        PII t = heap.top();heap.pop();
        int ver = t.second,distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > distance + w[i]){
                dis[j] = distance + w[i];
                prv[j] = ver;
                heap.push({dis[j],j});
            }
        }
    }
    if(dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
}
void print(){
    stack<int> path;
    int start = 1,end = n;
    path.push(end);
    int k = end;
    while(k != start){
        k = prv[k];
        path.push(k);
    }
    while(!path.empty()){
        cout << path.top() << ' ';
        path.pop();
    }
    cout << endl;
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof(h));
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    int t = dijkstra();
    print();
    cout << t << endl;
    return 0;
}