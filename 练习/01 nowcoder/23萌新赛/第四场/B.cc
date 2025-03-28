#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int unsigned long long
const int INF = (int)(pow(2,64))-1;
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int n,k,ans;
int a[N];
bool st[N];
bool func(int x){
    int cnt = 0;
    while(x > 0){
        cnt ++;
        x -= x & -x;
    }
    if(cnt == k) return true;
    return false;
}
void dfs(int u,int s){
    if(n == u){
        ans += func(s);
        return;
    }
    if(s == -1) dfs(u+1,a[u]);
    else dfs(u+1,s&a[u]);
    dfs(u+1,s);
}
void solve(){
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    dfs(0,-1);
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    while(t--) solve();
    return 0;
}
