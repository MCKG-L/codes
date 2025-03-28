#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  2e5 + 10,inf = 3e18;
/* 题目来源：abc_396_e
给定三个序列：X[1-M],Y[1-M],Z[1-M]（X和Y的值在[1,n]内）,问是否存在一个序列A[1-N],
满足A[X[i]] ^ A[Y[i]] = Z[i] (i=1,2,3,...,M)，并且要求A[i]的所有元素之和最小，求A
转化为图论问题：在X[i]和Y[i]之间建边，边权是Z[i],发现若要满足第一个条件，需要满足
不存在边权异或和不为0的环，在此基础上，考虑每一个连通块，发现如果连通块中的一个点的值确定，则该
连通块中所有点的值都是确定的，并且每个连通块的问题独立。对于每个连通块的第一个点，考虑二进制位的每一位，
（有两种可能取值0/1），在一种取值下统计整个连通块中在该bit上为1的个数，取其最小，即可满足该连通块中所有
数的和最小，每个联通块独立，问题得解
*/
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<PII>> a(n+1);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    vector<bool> st(n+1,false);
    vector<int> cnt(31),vals(n + 1),alls;
    auto dfs = [&](auto dfs,int u)->int{
        int res = 1;
        alls.push_back(u);
        for(auto [v,w] : a[u]){
            if(st[v]){
                if(vals[v] != (vals[u] ^ w)){
                    return -1;
                }
                continue;
            }
            st[v] = 1;
            vals[v] = vals[u] ^ w;
            for(int i=0;i<=30;i++) cnt[i] += (vals[v] >> i & 0x1);
            int t = dfs(dfs,v);
            if(t == -1) return -1;
            res += t;
        }
        return res;
    };
    int ans = 0;
    vector<int> res(n + 1);
    for(int i=1;i<=n;i++){
        if(st[i]) continue;
        st[i] = 1;
        cnt.resize(31,0);
        alls.clear();
        int sz =  dfs(dfs,i); //让连通块中的第一个数为0，只需跑一次
        if(sz == -1){
            cout << -1 << endl;
            return;
        }
        for(int k=0;k<=30;k++){
            if(cnt[k] <= sz - cnt[k]){
                for(auto v : alls){
                    if(vals[v] >> k & 0x1){
                        res[v] |= 1 << k;
                    }
                }
            }else{
                for(auto v : alls){
                    if(!(vals[v] >> k & 0x1)){
                        res[v] |= 1 << k;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << res[i] << ' ';
    }
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