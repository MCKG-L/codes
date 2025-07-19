#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e5 + 10;
int dfn[N],low[N],ts;
int cut[N],id[N];
vector<vector<int>> dcc;
int stk[N],top;
/*洛谷P8435
对于一个 n 个节点 m 条无向边的图，
请输出其点双连通分量的个数，并且输出每个点双连通分量。

不能处理自环的情况，需要在输入时排除，可以处理重边
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        if(u == v) continue;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    auto tarjan = [&](auto &tarjan,int u,int root)->void{
        dfn[u] = low[u] = ++ ts;
        stk[++top] = u;
        if(!a[u].size()){ //孤立点
            dcc.push_back({});
            dcc.back().push_back(u);
            return;
        }
        int cnt = 0;
        for(auto v : a[u]){
            if(!dfn[v]){
                cnt ++;
                tarjan(tarjan,v,root);
                low[u] = min(low[u],low[v]);
                if(low[v] >= dfn[u]){
                    if(u != root || cnt > 1) cut[u] = 1;
                    //记录vDCC
                    int y;
                    dcc.push_back({});
                    do{ 
                        y = stk[top--];
                        dcc.back().push_back(y);
                    }while(y != v);//注意不同,u不出栈
                    dcc.back().push_back(u);
                }
            }else{
                low[u] = min(low[u],dfn[v]);
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(tarjan,i,i);
    }
    cout << dcc.size() << endl;
    for(auto u : dcc){
        cout << u.size() << ' ';
        for(auto v : u){
            cout << v << ' ';
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
