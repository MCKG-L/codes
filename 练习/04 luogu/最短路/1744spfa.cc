#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;
const int N = 110,M = 2010;//无向图 双向存边
int e[M],h[N],ne[M],idx;
double w[M];
double dis[N];
bool st[N];
struct P{
    int x,y;
}p[N];
int n,m,s,f;
void add(int a,int b,double d){
    e[idx] = b;
    w[idx] = d;
    ne[idx] = h[a];
    h[a] = idx++;
}
double spfa(int s){
    // memset(dis,0x3f,sizeof dis);
    for(int i=0;i<N;i++) dis[i] = 1e9;
    queue<int> q;
    q.push(s);
    dis[s] = 0;st[s] = 1;
    while(q.size()){
        int t = q.front();q.pop();
        st[t] = 0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){
                dis[j] = dis[t] + w[i];
                if(!st[j]){
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }
    return dis[f];
}
int main()
{
    memset(h,-1,sizeof h);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        p[i] = {x,y};
    }
    cin >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        double d = sqrt(pow(p[a].x-p[b].x,2)+pow(p[a].y-p[b].y,2));
        add(a,b,d),add(b,a,d);
    }
    cin >> s >> f;
    cout << fixed << setprecision(2) << spfa(s) << endl;
    return 0;
}