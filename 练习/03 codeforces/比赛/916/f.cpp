#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int n,siz[N];
vector<vector<int>> a(N);
void solve(){
    cin >> n;
    for(int i=0;i<=n;i++) a[i].clear();
    for(int i=2;i<=n;i++){
        int x;cin >> x;
        a[x].push_back(i);
    }
    //caculate siz
    function<void(int)> init = [&](int u)->void{
        siz[u] = 1;
        for(auto v : a[u]){
            init(v);
            siz[u] += siz[v];
        }
    };
    init(1);
    //以u为根的子树中（已被占用k个节点）能形成的最大对数
    function<int(int,int)> dfs = [&](int u,int k)->int{
        int tot = 0,M = -1;
        for(auto v : a[u]){
            tot += siz[v];
            if(M == -1 || siz[M] < siz[v]) M = v;
        }
        if(tot == 0) return 0;
        if(siz[M] - k <= tot - siz[M]){
            return (tot - k) / 2;
        }
        int res = tot - siz[M];
        return res + dfs(M,max(0,k+res-1));
    };
    cout << dfs(1,0) << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}