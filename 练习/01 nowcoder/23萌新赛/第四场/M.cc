#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 1e6 + 10,M = 2e6 + 10;
int n,m;
int h[N],ne[M],e[M],idx;
int ans[N],sum[N];
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
int dfs(int u){
    if(sum[u] != -1) return sum[u];
    int cnt = 0,s = 0;
    for(int i=h[u];~i;i=ne[i]){
        int j = e[i];
        cnt += dfs(j);
        s ++;
    }
    ans[u] = cnt;
    sum[u] = s;
    return s;
}
void solve(){
    memset(ans,-1,sizeof ans);
    memset(sum,-1,sizeof sum);
    memset(h,-1,sizeof h);
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
    cout << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
