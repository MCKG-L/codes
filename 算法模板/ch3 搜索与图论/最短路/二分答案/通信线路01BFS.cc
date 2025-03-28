#include <iostream>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;
//二分答案 + 最短路 + 01BFS + 双端队列
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
int check(int max_n){
    //跑一遍最短路 0 1 边权 可以用双端队列优化
    //跑一遍01BFS
    memset(dis,0x3f,sizeof dis);
    memset(st,false,sizeof st);
    deque<int> q;q.push_front(1);
    dis[1] = 0;
    while(q.size()){
        int k = q.front();q.pop_front();
        if(st[k]) continue;
        st[k] = true;
        for(int i=h[k];i!=-1;i=ne[i]){
            int j = e[i],c = w[i] > max_n;
            if(dis[j] > dis[k] + c){
                dis[j] = dis[k] + c;
                if(c) q.push_back(j);
                else q.push_front(j);
            }
        }
    }
    if(dis[n] == 0x3f3f3f3f) return -1;//不能到达
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
        int t = check(mid);
        if(t == -1){
            cout << -1 << endl;
            return 0;
        }
        if(t) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
