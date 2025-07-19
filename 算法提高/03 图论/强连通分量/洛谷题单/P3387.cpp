#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,inf = 1e18;
struct SCC{ // [1,n] 
    vector<vector<int>> g, scc;//g是原图 scc存储每个强连通分量
    vector<int> dfn, low, stk, id; //id[i] 点i所属的强连通分量编号
	vector<int> w,hw;
    vector<bool> ins;
    int ts, n;
    SCC(const vector<vector<int> > &g,const vector<int> &hs) : g(g),hw(hs){
        n = (int)g.size();
        dfn.assign(n, 0);
        low.assign(n, 0);
        id.assign(n, -1);
        ins.assign(n, false);
        stk.reserve(n);
		w.assign(n + 1,0);
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
            scc.push_back({});
            int scc_cnt = scc.size();
            int y;
            do{
                y = stk.back();
                stk.pop_back();
                id[y] = scc_cnt;
                ins[y] = 0;
				w[scc_cnt] += hw[y];
                scc.back().push_back(y);
            }while(y != u);
        }
    }
    void build(){
        for(int i = 1; i < n; i++){
            if (!dfn[i]){
                tarjan(i);
            }
        }
    }
};
void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> w(n + 1,0);
	vector<vector<int>> g(n + 1);
	for(int i=1;i<=n;i++) cin >> w[i];
	for(int i=1;i<=m;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	SCC scc(g,w);
	vector<int> dp(n + 1,-inf);	
	queue<int> q;
	vector<int> ind(n + 1,0);
	int s = scc.scc.size();
	vector<vector<int>> a(s + 1);
	for(int i=1;i<=n;i++){
		for(auto v : g[i]){
			if(scc.id[i] != scc.id[v]){
				ind[scc.id[v]] ++;
 				a[scc.id[i]].push_back(scc.id[v]);
			}
		}
	}
	// cerr << s << endl;
	// for(int i=1;i<=s;i++){
	// 	cout << scc.w[i] << endl;
	// }
	for(int i=s;i>=1;i--){
		if(ind[i] == 0) dp[i] = scc.w[i];
		for(auto v : a[i]){
			dp[v] = max(dp[v],dp[i] + scc.w[v]);
		}
	}
	int ans = -inf;
	for(int i=1;i<=s;i++) ans = max(ans,dp[i]);
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