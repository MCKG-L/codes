#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 2e5 + 10;
/*abc_401_f
考察树的直径
结论：到树中某一结点最远的点一定是直径的端点之一
找直径的端点：先以任意点为树根找到直径的端点之一，再以该端点为根找到另一个端点
可以在过程中维护以每个点为根时的最大深度（到直径两端点距离的最大值）

本题给出两个树，定义f(i,j)为在两个树的i和j之间连一条边后，整个树的直径长度
求所有f(i,j)之和
维护好以每个点为根时的最大距离d[i],则f(i,j)=max(d1[i]+d2[i]+1,len)，len为两个树的直径较大值
枚举第一颗树的所有节点，第二棵树按照d[i]值排序，可以二分找到f(i,j)==len的分界点，另一部分可以通过
维护后缀和快速得到
*/
void solve(){
    vector<vector<int>> a[2];
    vector<int> N(2),dis[2],f[2];
    int len = -1;//zhijing 
    auto dfs1 = [&](auto dfs1,int i,int u,int fa)->void{
        for(auto v : a[i][u]){
            if(v == fa) continue;
            dis[i][v] = dis[i][u] + 1;
            f[i][v] = max(f[i][v],dis[i][v]);
            dfs1(dfs1,i,v,u);
        }
    };
    for(int i=0;i<2;i++){
        cin >> N[i];
        dis[i].assign(N[i]+1,0);
        f[i].assign(N[i]+1,0);
        a[i].assign(N[i]+1,{});
        for(int j=0;j<N[i]-1;j++){
            int u,v;
            cin >> u >> v;
            a[i][u].push_back(v);
            a[i][v].push_back(u);
        }
        dis[i][1] = 0;
        dfs1(dfs1,i,1,0);
        int Max = -1,p1 = 0;
        for(int j=1;j<=N[i];j++){
            if(dis[i][j] > Max){
                Max = dis[i][j],p1 = j;
            }
        }
        len = max(len,Max);
        dis[i][p1] = 0;
        dfs1(dfs1,i,p1,0);
        Max = 0;int p2 = 0;
        for(int j=1;j<=N[i];j++){
            if(dis[i][j] > Max){
                Max = dis[i][j];
                p2 = j;
            }
        }
        len = max(len,Max);
        dis[i][p2] = 0;
        dfs1(dfs1,i,p2,0);
    }
    vector<int> alls;
    for(int i=1;i<=N[1];i++){
        alls.push_back(f[1][i]);
    }
    sort(alls.begin(),alls.end());
    vector<int> pre(N[1] + 10);
    for(int i=N[1];i>=1;i--){
        pre[i] = pre[i+1] + alls[i-1];
    }
    int ans = 0;
    for(int i=1;i<=N[0];i++){
        int siz = f[0][i] + 1;
        int l = 1,r = N[1];
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(siz + alls[mid-1] < len) l = mid + 1;
            else r = mid - 1;
        }
        ans += r * len + (N[1] - r) * siz + pre[r+1];
    }
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