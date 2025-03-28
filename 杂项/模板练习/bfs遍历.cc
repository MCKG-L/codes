#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10010;
int e[N],ne[N],h[N],idx;
int d[N],q[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int bfs(int u){
    int hh = 0,tt = -1;
    memset(d,-1,sizeof d);
    q[ ++ tt] = u;
    d[u] = 0;
    while(hh <= tt){
        int t = q[hh ++];
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(d[j] == -1){
                d[j] = d[t] + 1;
                q[++ tt] = j;
            }
        }
    }
    return d[n];
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;cin >> a >> b;
        add(a,b),add(b,a);
    }
    int t = bfs(1);
    if(t == -1) cout << "impossible" << endl;
    else cout << t << endl;
    return 0;
}