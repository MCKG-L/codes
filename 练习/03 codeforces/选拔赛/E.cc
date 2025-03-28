#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 100010;
int e[N],h[N],ne[N],w[N],idx;
int dis[N];
bool st[N];
int n,m;
void add(int a,int b,int c){
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
int spfa(){
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;st[0] = 1;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int t = q.front();q.pop();
        st[t] = 0;
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){
                dis[j] = dis[t] + w[i];
                if(!st[j]) q.push(j),st[j] = true;
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
    int t = spfa();
    if(t == -1) puts("impossible");
    else cout << t << endl;
    return 0;
}
