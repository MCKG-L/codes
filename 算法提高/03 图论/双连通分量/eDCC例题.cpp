#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 2e6 + 10;
/*POJ 3177
给定一个连通图，若要满足：每一对点之间都有至少两条互相分离的路径
求最小的加边数

首先使用eDCC缩点，得到由桥构成的树，考虑叶子节点
隔点交替连接叶子节点，可以以最小的加边代价，满足上述条件
答案为：(s + 1) / 2，s是eDCC缩点之后，叶子节点的数目
*/
struct Node{
    int v,idx;
};
vector<vector<Node>> a(N);
int idx = 0;
stack<int> stk;
int dfn[N],low[N],ts;
vector<vector<int>> dcc;
int bri[N],siz[N],id[N];
void tarjan(int x,int e){
    dfn[x] = low[x] = ++ts;//标记
    stk.push(x);//入栈
    for(auto [v,id] : a[x]){
        if(!dfn[v]){//未遍历
            tarjan(v,id);
            low[x] = min(low[x],low[v]);
            if(low[v] > dfn[x]){ //是桥
                bri[id] = bri[id^1] = 1;
            }
        }else if(id != (e ^ 1)){ //不是反边
            low[x] = min(low[x],dfn[v]);
        }
    }
    if(dfn[x] == low[x]){
        dcc.push_back({});
        int y;
        do{ 
            y = stk.top();stk.pop();
            dcc.back().push_back(y);
            id[y] = dcc.size();
            siz[dcc.size()] ++;
        }while(y != x);
    }
}
void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back({v,idx++});
        a[v].push_back({u,idx++});
    }
    for(int i=1;i<=n;i++){
        if(dfn[i] == 0) tarjan(i,-1);
    }
    int cnt = dcc.size();
    vector<int> ind(cnt + 1);
    for(int i=1;i<=n;i++){
        for(auto [v,idx] : a[i]){
            if(bri[idx]) ind[id[v]] ++;
        }
    }
    int s = 0;
    for(int i=1;i<=cnt;i++){
        if(ind[i] == 1) s ++;
    }
    cout << (s + 1) / 2 << endl;
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
