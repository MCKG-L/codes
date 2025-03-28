#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,inf = 1e18;
/* abc_386_e
给出n个数，问从中选择k个数，得到的异或和最大是多少？
数据满足C(n,k) <= 1e6

trick:由于C(n,k) == C(n,n-k)
爆搜时搜到n-k时就可以提前返回，此时表示选取的n-k个数不选 t ^ tot 即为选择剩下的数的异或和
*/
void solve(){
    int n,k;
    cin >> n >> k;
    int tot = 0;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        tot ^= a[i];
    }
    int ans = -1;
    auto dfs = [&](auto dfs,int u,int cnt,int t)->void{
        if(cnt > k || u > n + 1){
            return;
        }
        if(cnt == k){
            ans = max(ans,t);
            return;
        }
        if(cnt == n - k){
            ans = max(ans,tot ^ t);
            return;
        }
        dfs(dfs,u+1,cnt,t);
        dfs(dfs,u+1,cnt+1,t^a[u]);
    };
    dfs(dfs,1,0,0);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}