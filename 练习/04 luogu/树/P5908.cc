#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10,M = 2 * N;
int h[N],ne[M],e[M],idx;
int dis[N];
int n,d;
void init(){
    memset(h,-1,sizeof h);
    idx = 0;
}
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(j == fa) continue;;
        dis[j] = dis[u] + 1;
        dfs(j,u);
    }
}
int main()
{
    cin >> n >> d;
    init();
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        add(a,b),add(b,a);
    }
    dis[1] = 0;
    dfs(1,0);
    int cnt = 0;
    for(int i=2;i<=n;i++){
        if(dis[i] <= d) cnt ++;
    }
    cout << cnt << endl;
}