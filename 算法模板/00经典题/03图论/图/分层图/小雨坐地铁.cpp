#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 1e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
/*https://ac.nowcoder.com/acm/problem/26257
一个城市有n个地铁站，m条线路，每条线路的进入价格为ci,在该线路上每坐一站都要额外支付d元，该条线路
上一共经过k个地铁站。给出起点和终点，问最小花费是多少？
建立分层图，建立一个有m层的分层图，表示第i条地铁线路上的道路情况，将相邻的两站之间连一条
边权为di的边。构建一个虚层，来实现换乘，从一个点进入虚层的代价为0，从虚层进入一个图层的代价为该条线路的进入价格。
从虚层的s站出发，到虚层的t站结束的价格即为所求。
*/
void solve(){
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    vector<vector<PII>> a(n * (m + 1) + 10);
    for(int i=0;i<m;i++){
        int c,d,k;
        cin >> c >> d >> k;
        int pre,cur;
        for(int j=0;j<k;j++){
            cin >> cur;
            if(j){
                a[i*n+pre].push_back({i*n+cur,d});
                a[i*n+cur].push_back({i*n+pre,d});
            }
            //next line
            a[n*m+cur].push_back({i*n+cur,c});
            a[i*n+cur].push_back({n*m+cur,0});
            pre = cur;
        }
    }
    vector<int> dis(n * (m + 1) + 10,inf);
    vector<bool> st(n * (m + 1) + 10);
    dis[n*m+s] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,n*m+s});
    while(heap.size()){
        auto [d,ver] = heap.top();
        heap.pop();
        if(st[ver]) continue;
        st[ver] = 1;
        for(auto [v,s] : a[ver]){
            if(dis[v] > d + s){
                dis[v] = d + s;
                heap.push({dis[v],v});
            }
        }
    }
    cout << (dis[n*m+t] == inf ? -1 : dis[n*m+t]) << endl;
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
