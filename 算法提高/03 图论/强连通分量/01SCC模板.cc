#include<iostream>
#include<cstring>
#include<vector>
#include <algorithm>
using namespace std;
using LL = long long;
struct SCC{
    vector<vector<int> > g, scc;
    vector<int> dfn, low, stk, id;
    vector<bool> ins;
    int ts, n;
    SCC(const vector<vector<int> > &g) : g(g){
        n = (int)g.size();
        dfn.assign(n, 0);
        low.assign(n, 0);
        id.assign(n, -1);
        ins.assign(n, false);
        stk.reserve(n);
        ts = 0;
        build();
    }
    //栈中元素的含义是强连通分量中的点
    void tarjan(int u){
        dfn[u] = low[u] = ++ts;
        stk.push_back(u);
        ins[u] = 1;
        for(auto j : g[u]){
            if (!dfn[j]){
                tarjan(j);
                low[u] = min(low[u], low[j]);
            }
            else if (ins[j]) low[u] = min(low[u], dfn[j]);
        }
        if (dfn[u] == low[u]){ //一个强连通分量中的最低点（时间戳最小的点）
            int scc_cnt = scc.size();
            scc.push_back({});
            int y;
            do{
                y = stk.back();
                stk.pop_back();
                id[y] = scc_cnt;
                ins[y] = 0;
                scc.back().push_back(y);
            }while(y != u);
        }
    }
    void build(){
        for(int i = 0; i < n; i++){
            if (!dfn[i]){
                tarjan(i);
            }
        }
    }
};

int main(){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int> > g(n);
        while(m--){
            int a, b;
            cin >> a >> b;
            a--, b--;
            g[a].push_back(b);
        }
        SCC scc(g);
        const int s = scc.scc.size();
        vector<int> cnt(s);
        vector<LL> sum(s);
        auto &p = scc.scc;
        vector<pair<int, LL> > dp(n);
        for(int i = 0; i < s; i++){
            cnt[i] = p[i].size();
            for(auto x : p[i]){
                sum[i] -= a[x];
            }
            dp[i] = {cnt[i], sum[i]};
        }
        for(int i = 0; i < s; i++){
            for(auto x : p[i]){
                for(auto j : g[x]){
                    if (scc.id[j] != i){
                        int k = scc.id[j];
                        pair<int, LL> t = {cnt[i] + dp[k].first, sum[i] + dp[k].second};
                        dp[i] = max(dp[i], t);
                    }
                }
            }
        }
        auto ans = *max_element(dp.begin(), dp.end());
        cout << ans.first << ' ' << -ans.second << '\n';
    }

}