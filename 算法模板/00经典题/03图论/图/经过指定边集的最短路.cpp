#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 401;
/*abc_369_e
给出一个无向图，每个边有编号和权值，有q次询问：
给出k个边的编号，必须经过这k条边，问从1到n的最短路
1<=k<=5 1<=q<=3000
暴力+floyd O(n^3+q*k!*2^k)
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<array<int,3>> alls(m + 1);
    vector<vector<int>> dis(n + 1,vector<int>(n + 1,inf));
    for(int i=1;i<=n;i++) dis[i][i] = 0ll;
    for(int i=1;i<=m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        alls[i] = {u,v,c};
        dis[v][u] =  dis[u][v] = min(dis[u][v],c);
    }
    auto floyd = [&]()->void{
        for(int k=1;k<=n;k++){
            for(int j=1;j<=n;j++){
                for(int i=1;i<=n;i++){
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    };
    floyd();
    vector<int> order;
    int q;cin >> q;
    while(q --){
        int k;cin >> k;
        order.resize(k);
        vector<int> a(k);
        for(int i=0;i<k;i++) cin >> a[i];
        iota(order.begin(),order.end(),0);
        int ans = inf;
        do{
            for(int j=0;j<1<<k;j++){
                int s = 0,lst = 1;
                for(int i=0;i<k;i++){
                    int d = j >> i & 0x1;
                    auto &ver = alls[a[order[i]]];
                    s += dis[lst][ver[d]] + ver[2];
                    lst = ver[d^1];
                }
                ans = min(ans,s + dis[lst][n]);
            }
        }while(next_permutation(order.begin(),order.end()));
        cout << ans << endl;
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