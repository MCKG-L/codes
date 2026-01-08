#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 3e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
/*https://www.matiji.net/exam/brushquestion/62/4693/305EE97B0D5E361DE6A28CD18C929AF0
(∑i=1n−1​∑j=i+1n​(ai​+aj​)popcount(alca(i,j)​)) mod (109+7)
给出一棵树，节点编号为1~n,每个节点有一个权值a[i]
对于所有的点对(i,j)，求(a[i] + a[j])^(popcount(lca(i,j)))之和,其中lca(i,j)表示节点i和j的最近公共祖先
popcount(x)表示x的二进制位中1的个数
拆贡献：考虑以每个节点作为LCA时产生的贡献:
假设当前节点x作为LCA，popcount(a[x]) = m
贡献为：(ai + ax)^m + (ai+1 + ax)^m + ... + (ay + ax)^m
考虑计算的过程，这里ax实际上代表了一个集合（已考虑的节点集合）
for i in m:C(m,i)*ai^i*ax^m-i
记f[x][i]为以x为根时，所有子节点的i次幂之和
for i in m:C(m,i)*f[y][i]*ax^m-i
这里ax表示一个集合，即以x为根且已考虑过的节点集合,在dfs的过程中维护：
for i in m:C(m,i)*f[y][i]*f[x][m-i]
预处理C(m,i)，在dfs过程中维护f[x][i]并统计答案
*/
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> mi(n + 1,vector<int>(32,0));
    vector<vector<int>> C(32,vector<int>(32,0));
    C[0][0] = 1;
    int m = 31;
    for(int i=1;i<=m;i++){
        C[i][0] = 1;
        for(int j=1;j<=m;j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    for(int i=1;i<=n;i++){
        mi[i][0] = 1ll;
        for(int j=1;j<=m;j++){
            mi[i][j] = mi[i][j-1] * a[i] % mod;
        }
    }
    vector<vector<int>> f(n + 1,vector<int>(32,0));
    int ans = 0;
    auto cal = [&](int x)->int{
        int res = 0;
        while(x){
            res += x & 0x1;
            x >>= 1;
        }
        return res;
    };
    auto dfs = [&](auto dfs,int u,int fa)->void{
        for(int i=0;i<=m;i++){
            f[u][i] = mi[u][i];
        }
        int len = cal(a[u]);
        for(auto v : g[u]){
            if(v == fa) continue;
            dfs(dfs,v,u);
            for(int i=0;i<=len;i++){
                ans = (ans + C[len][i] * f[u][len-i] % mod * f[v][i] % mod) % mod;
            }
            for(int i=0;i<=m;i++){
                f[u][i] = (f[u][i] + f[v][i]) % mod;
            }    
        }
    };
    dfs(dfs,1,0);
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
