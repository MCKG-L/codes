#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
const int N = 3e3+10,M = 7e4+10;
int e[M],h[N],ne[M],w[M],idx;
int ind[N];
int dis[N];
bool st[N];
vector<int> p[N];
int n,m;
void add(int a,int b,int c){
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}
void Dijkstra(){
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
                if(!ind[j]) heap.push({dis[j],j});
            }
        }
        for(int i=0;i<p[k].size();i++){
            int j = p[k][i];
            dis[j] = max(dis[j],dis[k]);
            ind[j]--;
            if(!ind[j]) heap.push({dis[j],j});
        }
    }
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
    for(int i=1;i<=n;i++){
        int l;cin >> l;
        for(int j=1;j<=l;j++){
            int x;cin >> x;
            ind[i]++;
            p[x].push_back(i);
        }
    }
    Dijkstra();
    cout << dis[n] << endl;
    return 0;
}