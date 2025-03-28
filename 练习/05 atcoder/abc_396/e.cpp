#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  2e5 + 10,inf = 3e18;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<PII>> a(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    vector<bool> st(n+1,false);
    vector<int> cnt(100),vals(n + 1),alls;
    auto dfs = [&](auto dfs,int u)->int{
        int res = 1;
        alls.push_back(u);
        for(auto [v,w] : a[u]){
            if(st[v]){
                if(vals[v] != (vals[u] ^ w)){
                    return -1;
                }
                continue;
            }
            st[v] = 1;
            vals[v] = vals[u] ^ w;
            for(int i=0;i<=30;i++) cnt[i] += (vals[v] >> i & 0x1);
            int t = dfs(dfs,v);
            if(t == -1) return -1;
            res += t;
        }
        return res;
    };
    int ans = 0;
    vector<int> res(n + 1);
    for(int i=1;i<=n;i++){
        if(st[i]) continue;
        st[i] = 1;
        cnt.resize(100,0);
        alls.clear();
        int sz =  dfs(dfs,i);
        if(sz == -1){
            cout << -1 << endl;
            return;
        }
        for(int k=0;k<=30;k++){
            if(cnt[k] <= sz - cnt[k]){
                for(auto v : alls){
                    if(vals[v] >> k & 0x1){
                        res[v] |= 1 << k;
                    }
                }
            }else{
                for(auto v : alls){
                    if(!(vals[v] >> k & 0x1)){
                        res[v] |= 1 << k;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << res[i] << ' ';
    }
    cout << endl;
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