#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
//手写堆 可以保证堆中始终有n个元素
//优先队列 会有多余的点 最多有m个点
/*
1、初始化距离：dis[1] = 0,dis[i] = 无穷大
2、n次循环，每一次循环在未确定最短距离的点中找到距离最近的点，然后用该点更新所有点的距离
堆优化：每一次循环在未确定最短距离的点中找到距离最近的点
该算法基于贪心算法
*/
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
    priority_queue<PII,vector<PII>,greater<PII>> heap;//小根堆 first存距离 因为默认按照pair的第一个元素排序
    heap.push({0,1});
    while(heap.size()){
        PII t = heap.top();heap.pop();//取出最小距离的点 堆顶元素（小根堆）
        int ver = t.second,distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > distance + w[i]){
                dis[j] = distance + w[i];
                prv[j] = ver;
                heap.push({dis[j],j});//把有距离更新的点放入队列
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
    // memset(g,0x3f,sizeof(g));
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