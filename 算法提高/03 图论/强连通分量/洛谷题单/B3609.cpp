#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N = 100;
void solve(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> dfn(n + 1),low(n + 1),stk(n + 1),ins(n + 1),id(n + 1);
	int top = 0,ts = 0,scc = 0;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	auto tarjan = [&](auto tarjan,int u)->void{
		dfn[u] = low[u] = ++ ts;
		stk[++top] = u;ins[u] = true;
		for(auto v : g[u]){
			if(!dfn[v]){
				tarjan(tarjan,v);
				low[u] = min(low[u],low[v]);
			}else if(ins[v]){
				low[u] = min(low[u],dfn[v]);
			}
		}
		if(dfn[u] == low[u]){
			int y;scc ++;
			do{
				y = stk[top--];
				ins[y] = false;
				id[y] = scc;
			}while(y != u);
		}
	};
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(tarjan,i);
	}
	map<int,int> mp;
	vector<set<int>> ans(scc + 1);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		int k = id[i];
		// cerr << k << endl;
		if(!mp.count(k)){
			mp[k] = ++ cnt;
			ans[cnt].insert(i);
		}else{
			ans[mp[k]].insert(i);
		}
	}
	cout << scc << endl;
	for(int i=1;i<=scc;i++){
		for(auto v : ans[i]){
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