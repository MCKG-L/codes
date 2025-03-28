#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 3e18;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> g(n+1,vector<bool>(n+1,false));
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    for(int i=1;i<=n;i++){
        g[i][i] = 1;
    }
    vector<int> a;
    int ans = -1;
    a.reserve(n + 1);
    for(int k=0;k<1<<n;k++){
        a.clear();
        for(int i=0;i<n;i++){
            if(k >> i & 0x1) a.push_back(i + 1);
        }
        // cerr << a.size() << endl;
        bool ok = 1;
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                if(g[a[i]][a[j]] == 0){
                    ok = 0; 
                    break;
                }
            }
            if(!ok) break;
        }
        // cerr << ans << endl;
        if(ok) ans = max(ans,(int)a.size());
    }
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