#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
// 二分答案 + 最短路 + 堆优化Dijkstra
typedef pair<int,int> PII;
const int N = 1010,M = 20010;
int e[M],h[N],ne[M],w[M],idx;
int dis[N];
bool st[N];
int n,p,k;
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
bool check(int max_n){
    //跑一遍最短路 0 1 边权 可以用双端队列优化
    //跑一遍堆优化的Dijkstra
    memset(dis,0x3f,sizeof dis);
    memset(st,false,sizeof st);
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
            int c = w[i] > max_n;
            if(dis[j] > d + c){
                dis[j] = d + c;
                heap.push({dis[j],j});
            }
        }
    }
    return dis[n] <= k;
}
int main()
{
    memset(h,-1,sizeof h);//不要忘了
    cin >> n >> p >> k;
    int max_n = 0;
    while(p--){
        int a,b,c;
        cin >> a >> b >> c;
        max_n = max(max_n,c);
        add(a,b,c),add(b,a,c);
    }
    int l = 0,r = max_n + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(l == max_n + 1) cout << -1 << endl;
    else cout << l << endl;
    return 0;
}
