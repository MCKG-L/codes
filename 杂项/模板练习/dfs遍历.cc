#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10010;
int e[N],h[N],ne[N],idx;
bool st[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void dfs(int u){
    st[u] = 1;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j = e[i];
        if(!st[j]){
            cout << u << "->" << j << "->";
            dfs(j);
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b;
        cin >> a >> b;
        add(a,b),add(b,a);
    }
    dfs(1);
    return 0;
}