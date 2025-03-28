#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 10010,M = 1e5 + 10;
//二分图的最大匹配 匈牙利算法
int h[N],ne[M],e[M],idx;
int n1,n2,m;
int match[N];
bool st[N];
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
bool find(int x){
    for(int i=h[x];~i;i=ne[i]){
        int j = e[i];
        if(st[j]) continue;
        st[j] = 1;
        if(!match[j] || find(match[j])){
            match[j] = x;
            return 1;
        }
    }
    return false;
}
void solve(){
    cin >> n1 >> n2 >> m;
    for(int i=1;i<=n1;i++) h[i] = -1;
    while(m--){
        int u,v;
        cin >> u >> v;
        add(u,v);
    }
    int ans = 0;
    for(int i=1;i<=n1;i++){
        for(int i=1;i<=n2;i++) st[i] = 0;
        if(find(i)) ans ++;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
	int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}