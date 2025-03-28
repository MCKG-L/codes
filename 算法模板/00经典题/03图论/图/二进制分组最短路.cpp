#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,inf = 1e18;
/* 题目来源：abc_245_g
给出一张n个节点m条边的无向图，每个节点所属的类别为A[i],给定l个特殊的点B[1...l]
对于每个点i，问点i到与它所属类别不同的特殊点的距离的最小值

如果不考虑类别，则问题就是从特殊点开始的多源最短路问题，现在考虑类别
可以按照类别的二进制位进行log(l)次分组，每次根据二进制位的不同分为两组S1,S2
从S1中特殊点开始跑多源最短路，更新S2中点的距离
再从S2中特殊点开始跑多源最短路，更新S1中点的距离

这样进行分组，可以保证任意两个类别不同的点都有出现在两个不同集合的情况
*/
void solve(){
    int n,m,k,l;
    cin >> n >> m >> k >> l;
    vector<int> A(n + 1);
    vector<bool> all(n + 1,false);
    for(int i=1;i<=n;i++) cin >> A[i];
    for(int i=1;i<=l;i++){
        int x;cin >> x;
        all[x] = true;
    }
    vector<vector<PII>> g(n + 1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int> ans(n + 1,inf);
    vector<bool> st;
    st.reserve(n + 1);
    auto Dijkstra = [&](priority_queue<PII,vector<PII>,greater<PII>> &heap,vector<int> &dis)->void{
        st.assign(n + 1,false);
        while(heap.size()){
            auto [t,ver] = heap.top();
            heap.pop();
            if(st[ver]) continue;
            st[ver] = true;
            for(auto [v,w] : g[ver]){
                if(t + w < dis[v]){
                    dis[v] = t + w;
                    heap.push({dis[v],v});
                }
            }
        }
    };
    for(int d=0;d<=30;d++){
        priority_queue<PII,vector<PII>,greater<PII>> heap,heap2;
        vector<int> dis(n + 1,inf),dis2(n + 1,inf);
        for(int i=1;i<=n;i++){
            if(A[i] >> d & 0x1){
                if(all[i]){
                    heap.push({0,i});
                    dis[i] = 0;
                }
            }else{
                if(all[i]){
                    heap2.push({0,i});
                    dis2[i] = 0;
                }
            }
        }
        Dijkstra(heap,dis);
        Dijkstra(heap2,dis2);
        for(int i=1;i<=n;i++){
            if(!(A[i] >> d & 0x1)) ans[i] = min(ans[i],dis[i]);
            else ans[i] = min(ans[i],dis2[i]);
        }
    }
    for(int i=1;i<=n;i++) cout << (ans[i] == inf ? -1 : ans[i]) << ' ';
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