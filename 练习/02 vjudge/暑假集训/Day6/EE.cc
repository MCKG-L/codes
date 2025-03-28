#include <iostream>
#include <map>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
map<pair<int,int>,int> mp;
int n,m;
int p[N];
int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) p[i] = i;
	while(m--){
		int u,v;
		cin >> u >> v;
		u = find(u),v = find(v);
		if(u != v) p[u] = v;
	}
	int k;cin >> k;
	while(k--){
		int x,y;
		cin >> x >> y;
		x = find(x),y = find(y);
		mp[{x,y}] = 1,mp[{y,x}] = 1;
	}
	int q;cin >> q;
	while(q--){
		int a,b;
		cin >> a >> b;
		a = find(a),b = find(b);
		if(mp[{a,b}] || mp[{b,a}]){
			puts("No");
		}else{
			puts("Yes");
		}
	}
	return 0;
}