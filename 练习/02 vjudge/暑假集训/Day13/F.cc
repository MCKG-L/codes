#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10,M = 2 * N;
int h[N],ne[M],e[M],idx;
int n,k,x,y;
bool st1[N],st2[N];
/*
记录每条路径需要走几次，如果路径在x->y的路径上，则只需要走一遍
否则如果需要经过，一定是走两遍
先将必须经过的点的对应路径标记为需要走两次，如果发现在x->y路径上，则标记为需要走一遍
计算答案时，首先判断是否需要走一遍，如果不是，再判断是否需要走两遍
*/
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void dfs(int u,int f){
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(j == f) continue;
        dfs(j,u);
        if(st1[j]) st1[u] = 1;
        else if(st2[j]) st2[u] = 1;
    }
}
void solve(){
    cin >> n >> k >> x >> y;
    memset(h,-1,(n+2)*4);
    memset(st1,0,n+2);//注意类型时bool，不是int!!!
    memset(st2,0,n+2);
    idx = 0;st1[y] = 1;
    for(int i=0;i<k;i++){
        int x;cin >> x;
        st2[x] = 1;
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        add(u,v),add(v,u);
    }
    dfs(x,x);
    long long ans = 0;
    for(int i=1;i<=n;i++){
        if(i == x) continue;
        if(st1[i]) ans ++;
        else if(st2[i]) ans += 2;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}