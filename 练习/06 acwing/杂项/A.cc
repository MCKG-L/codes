#include <bits/stdc++.h>
using namespace std;
const int N = 510,M = 1e5 + 10;
int h[N],ne[M],e[M],idx;
int n1,n2,m;
bool st[N];
int match[N];
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
int dfs(int u){
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        if(st[j]) continue;
        st[j] = 1;
        if(!match[j] || dfs(match[j])){
            match[j] = u;
            return true;
        }
    }
    return false;
}
void solve(){
    cin >> n1 >> n2 >> m;
    for(int i=0;i<=n1;i++) h[i] = -1;
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        add(a,b);
    }
    int cnt = 0;
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n1;j++) st[j] = 0;
        if(dfs(i)) cnt ++;
    }
    cout << cnt << endl;
}
int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}