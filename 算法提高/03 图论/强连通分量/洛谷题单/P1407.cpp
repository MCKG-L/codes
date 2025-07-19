#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10;
struct SCC{ // [1,n] 
    vector<vector<int>> g, scc;//g是原图 scc存储每个强连通分量
    vector<int> dfn, low, stk, id; //id[i] 点i所属的强连通分量编号
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
            scc.push_back({});
            int scc_cnt = scc.size();
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
        for(int i = 1; i < n; i++){
            if (!dfn[i]){
                tarjan(i);
            }
        }
    }
};
void solve(){
	int n;cin >> n;
	n *= 2;
	vector<vector<int>> g(n + 1);
	map<string,int> mp;
	int now = 1;
	for(int i=1;i<=n/2;i++){
		string s1,s2;
		cin >> s1 >> s2;
		mp[s1] = now ++;
		mp[s2] = now ++;
		g[mp[s1]].push_back(mp[s2]);
	}
	int m;cin >> m;
	for(int i=0;i<m;i++){
		string s1,s2;
		cin >> s1 >> s2;
		g[mp[s2]].push_back(mp[s1]);
	}
	SCC scc(g);
	for(int i=1;i<=n-1;i+=2){
		int a = scc.id[i],b = scc.id[i + 1];
		if(a == b){
			cout << "Unsafe" << endl;
		}else{
			cout << "Safe" << endl;
		}
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