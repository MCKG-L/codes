#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
int f[12],n;
map<int,int> mp;
void dfs(int u,int a,int b){
    if(u == n + 1){
        mp[a] += b;
        return;
    }
    dfs(u+1,a,b),dfs(u+1,a+f[u]/2,-b),dfs(u+1,a+f[u],-b);
}
void solve(){
    int q;cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> f[i];
    dfs(1,0,1);
    while(q--){
        int a;cin >> a;
        cout << mp[a] << endl;
    }
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}