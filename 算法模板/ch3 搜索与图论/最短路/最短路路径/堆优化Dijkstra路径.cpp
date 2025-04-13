#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 2e5 + 10;
void solve(){
    int n,m,s;
    cin >> n >> m >> s;
    vector<vector<PII>> a(n + 1);
    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        a[u].push_back({v,c});
    }
    vector<int> dis(n + 1,inf);
    vector<bool> st(n + 1,false);
    auto Dijkstra = [&](int s)->void{
        priority_queue<PII,vector<PII>,greater<PII>> heap;
        dis[s] = 0;
        heap.push({0,s});
        while(heap.size()){
            auto [d,ver] = heap.top();heap.pop();
            if(st[ver]) continue;
            st[ver] = true;
            for(auto [v,c] : a[ver]){
                if(dis[v] > d + c){
                    dis[v] = d + c;
                    heap.push({d+c,v});
                }
            }
        }
    };
    Dijkstra(s);
    for(int i=1;i<=n;i++) cout << dis[i] << ' ';
    cout << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T = 1;
	#ifdef LOCAL
		freopen("D:\\Others\\desktop\\text.in","r",stdin);
	#endif
	// cin >> T;
	while(T --) solve();
	return 0;
}