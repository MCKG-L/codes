#include <bits/stdc++.h>
using namespace std;
const int N = 1010,M = 10010;
int h[N],e[M],nex[M],id;
bool istrue[N];
void dfs(int u){
    cout << "->" << u;
    istrue[u] = true;
    for(int i=h[u];i!=-1;i=nex[i]){
        int j = e[i];
        if(!istrue[j]){
            dfs(j);
        }
    }
}
void add(int a,int b){
    e[id] = b;
    nex[id] = h[a];
    h[a] = id++;
}
int main()
{
    int n,m,a,b;
    memset(h,-1,sizeof(h));
    cout << "输入点数和边数：" << endl;
    cin >> n >> m;
    cout << "输入起点和终点的值：" << endl;
    for(int i=1;i<=m;i++){
        cin >> a >> b;
        add(a,b);
        add(b,a); //加上则为无向图，双向边
    }
    for(int i=1;i<=n;i++){
        memset(istrue,false,sizeof(istrue));
        cout << "从点" << i << "出发深度搜索:";
        dfs(i);
        cout << endl;
    }
    return 0;
}