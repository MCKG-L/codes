#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,inf = 1e18;
/* 题目来源 洛谷P1073
题意：给出一个n个点m条边的图（可能有环）,代表n座城市，对于某一物品，每个城市都有一个售价，
从1号点走到n号点，可以从某一个城市买入，然后在后续的某一个城市卖出，问收益最大是多少？
可以不进行交易，收入为0，每个城市可以多次进入

分层图---最长路
考虑三个状态：
1、不进行交易操作，则在原图上
2、进行了买入操作，但是没有卖出
3、已经进行了买入并且已经卖出

由于在城市中穿梭不需要有消耗，只考虑交易带来的收益，所以在每个层次的图中，边权都是0
考虑三个层次如何进行定义边权：买入操作会使其进入第二个层次的图中，边权为-cost，
卖出操作会使其进入第三个状态图中，边权为cost

转换为求最长路问题，将点的全中取负，跑一边spfa最短路，-dis[3*n]即进行交易得到的最大收益
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<PII>> g(3 * n + 1);
    vector<int> dis(3 * n + 1,inf),w(3 * n + 1);
    vector<bool> st(n + 1);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        w[i] = -x;
    }
    for(int i=0;i<m;i++){
        int u,v,t;
        cin >> u >> v >> t;
        g[u].push_back({v,0});
        g[n+u].push_back({n+v,0});
        g[2*n+u].push_back({2*n+v,0});
        if(t == 2){
            g[v].push_back({u,0});
            g[n+v].push_back({n+u,0});
            g[2*n+v].push_back({2*n+u,0});
        }
    }
    for(int i=1;i<=n;i++){
        g[i].push_back({n+i,-w[i]});
        g[n+i].push_back({2*n+i,w[i]});
    }
    auto spfa = [&](){
        queue<int> q;
        dis[1] = 0;
        q.push(1);
        st[1] = true;
        while(q.size()){
            auto k = q.front();q.pop();
            st[k] = false;
            for(auto [v,cost] : g[k]){
                if(dis[v] > dis[k] + cost){
                    dis[v] = dis[k] + cost;
                    if(!st[v]) q.push(v);
                }
            }
        }
    };
    spfa();
    cout << -min(dis[n],dis[3*n]) << endl;
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