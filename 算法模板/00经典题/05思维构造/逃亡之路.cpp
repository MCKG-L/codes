#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 3e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
/* https://www.matiji.net/exam/brushquestion/60/4693/305EE97B0D5E361DE6A28CD18C929AF0
给出n个节点，每个节点有一个取值范围[l,r]，有m个限制：u,v,w，满足
节点u和节点v之间的权值之和为w，可能包含自环
问：能否可以合理的分配给每个节点权值，满足这m个限制，如果能，求可以得到的权值和的最大值
如果不考虑环：则每个点可以表示为kx+b的形式，进而根据本身的[l,r]限制可以求出n个x取值范围
最终取交集，即为合理的x取值范围
考虑环：
如果是偶环：需要满足w = node[u].b + node[v].b
如果是奇环：则2*x + node[u].b + node[v].b = w,即w-(node[u].b+node[v].b)需要是偶数
且可以确定x的值
如果存在多个奇环，确定了不同的x值，则无解
维护sumk和sumb，如果确定了x值，则答案为sumk*x+sumb
否则：sumk*x+sumb，x->[l,r]，此时需要考虑sumk的正负，使得式子达到最大值
分别考虑所有的连通块即可
*/
struct Node{
    int k,b,l,r;
};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<PII>> a(n + 1);
    vector<Node> node(n + 1);
    for(int i=1;i<=n;i++){
        int l,r;cin >> l >> r;
        node[i].l = l,node[i].r = r;
    }
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    int sumk = 0,sumb = 0,l = 0,r = 0,x = 0;
    bool ok = 1;
    vector<bool> st(n + 1);
    //k b
    auto dfs1 = [&](auto dfs1,int u)->void{
        sumk += node[u].k,sumb += node[u].b;
        st[u] = 1;
        for(auto [v,w] : a[u]){
            int kx = -node[u].k,kb = w - node[u].b;
            if(st[v]){ //ring
                if(node[u].k + node[v].k != 0){ //odd ring
                    if((w - (node[u].b + node[v].b)) % 2 != 0){
                        ok = false;
                        return;
                    }
                    int tmpx = ((w - (node[u].b + node[v].b)) / (node[u].k + node[v].k));
                    if(x != inf && tmpx != x){
                        ok = false;
                        return;
                    }
                    x = tmpx;
                }else{ //even ring
                    if(w != node[u].b + node[v].b){
                        ok = false;
                        return;
                    }
                }
                continue;
            }
            node[v].k = kx,node[v].b = kb;
            dfs1(dfs1,v);
        }
    };
    vector<bool> vis(n + 1,false);
    auto dfs2 = [&](auto dfs2,int u)->void{
        if(!ok) return;
        vis[u] = 1;
        for(auto [v,w] : a[u]){
            if(vis[v]) continue;
            int tl = (node[v].l - node[v].b) / node[v].k;
            int tr = (node[v].r - node[v].b) / node[v].k;
            if(tl > tr) swap(tl,tr);
            l = max(l,tl),r = min(r,tr);
            if(l > r){
                ok = false;
                return;
            }
            dfs2(dfs2,v);
        }
    };
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(st[i]) continue;
        sumk = 0,sumb = 0;
        node[i].k = 1,node[i].b = 0;
        x = inf;
        dfs1(dfs1,i);
        l = node[i].l,r = node[i].r;
        dfs2(dfs2,i);
        if(x != inf){
            if(x < l || x > r){
                ok = 0;break;
            }
            ans += sumk * x + sumb;
        }else{
            if(sumk >= 0){
                ans += r * sumk + sumb;
            }else{
                ans += l * sumk + sumb;
            }
        }
    }
    if(!ok){
        cout << "NO" << endl;
    }else{
        cout << "YES" << '\n' << ans << endl;
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
