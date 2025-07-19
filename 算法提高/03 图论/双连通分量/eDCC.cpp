#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 2e6 + 10;
/*求边的双连通分量eDCC
注意需要记录边的编号(判断反边)，(0,1)、(2,3)、(4,5)...是一组反边
可以通过id == (e ^ 1)判断是否互为反边
缩点后的图形是由桥构成的树
*/
//输出所有的边连通分量
struct Node{
    int v,idx;
};
vector<vector<Node>> a(N);
int idx = 0;
stack<int> stk;
int dfn[N],low[N],ts;
vector<vector<int>> dcc;
int bri[N],siz[N];
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
    cout << dcc.size() << endl;
    for(auto u : dcc){
        cout << u.size() << ' ';
        for(auto v : u){
            cout << v <<  ' ';
        }
        cout << endl;
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
