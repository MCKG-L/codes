#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
void solve(){
    int n = 5;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector< pair<int,string>> ans;
    ans.reserve(35);
    vector<int> st(10,false),p(10,-1);
    auto dfs = [&](auto dfs,int u,int s)->void{
        if(u >= n){
            int sum = 0;
            string s;
            for(int i=0;i<n;i++){
                if(p[i] != -1){
                    s += 'A' + p[i];
                    sum += a[p[i] + 1];
                }
            }
            ans.push_back({sum,s});
            return;
        }
        for(int i=s;i<n;i++){
            if(st[i]) continue;
            st[i] = 1;
            p[u] = i;
            dfs(dfs,u+1,i+1);
            p[u] = -1;
            dfs(dfs,u+1,i);
            st[i] = 0;
        }
    };
    dfs(dfs,0,0);
    sort(ans.begin(),ans.end(),[&](pair<int,string> p1,pair<int,string> p2){
        if(p1.first != p2.first) return p1.first > p2.first;
        return p1.second < p2.second;
    });
    for(auto [_,name]:ans){
        cout << name << endl;
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