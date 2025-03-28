#include<bits/stdc++.h>
using namespace std;
int n, m, t; string s;
vector<vector<int>>v;
vector<int>vis;
int bfs() {
	queue<int>q;
	q.push(m);
	while (q.size()) {
		 int pos = q.front();
		 q.pop();
		 for (auto& x : v[pos]) {
			 if (vis[x] <= 100)q.push(x);
			 vis[x]++;
	   }
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 cin >> t;
	while (t--) {
		cin >> n >> m;
		v.clear(); vis.clear();
		v.resize(n+2); vis.resize(n+2);
		map<int, string>mp;
		for (int i = 1; i <= n; i++) {
			cin >> s; mp[i] = s;
		}
		int cnt = 0; int x;
		for (int i = 1; i <= n; i++) {
			cin >> cnt;
			while (cnt--) {
				cin >> x;
				v[i].push_back(x);
	        }
		}
		bfs();
		vector<int>st;
		for (int i = 1; i <=n; i++) {
			if (vis[i] > 100)st.push_back(i);
		}
		if (st.size() == 0) {
			cout << "No one is disturbed!\n";
			continue;
		}
		cout << st.size() << "\n";
		for (auto& it : st) {
			cout << mp[it] << " ";
		}
		cout << "\n";

	}
	return 0;
}
