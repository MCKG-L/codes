#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n + 1);
    a[0] = -9;int cnt = 0;
    vector<vector<int>> ans;
    auto dfs = [&](auto dfs,int u)->void{
        if(u > n - 1){
            ans.push_back({});
            for(int i=1;i<n;i++){
                ans.back().push_back(a[i]);
            }
            cnt += (m - a[n-1] - 10 + 1);
            return;
        }
        for(int i=a[u-1] + 10;i + (n - u) * 10 <= m;i++){
            a[u] = i;
            dfs(dfs,u+1);
        }
    };
    dfs(dfs,1);
    cout << cnt << endl;
    for(auto &p : ans){
        int x = p.back() + 10;
        while(x <= m){
            for(auto c : p) cout << c << ' ';
            cout << x << endl;
            x ++;
        }
    }
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