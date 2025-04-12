#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int mod = 1e9 + 7,inf = 1e18;
/*
给出一个迷宫，起点和终点。你在走迷宫过程中可以暴力破坏墙壁（踢一脚）,
每踢一脚可以使得前方两个单位的墙壁破坏。问走到终点至少需要踢多少脚？

01BFS宽搜即可
*/
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
struct Node{
	int x,y,t;
	bool operator<(const Node &p)const{
		return t < p.t;
	}
};
void solve(){
	int n,m;
	cin >> n >> m;
	vector<vector<char>> a(n + 1,vector<char>(m + 1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cin >> a[i][j];
	}
	vector<vector<int>> dis(n + 1,vector<int>(m + 1,inf));
	vector<vector<bool>> st(n + 1,vector<bool>(m + 1,false));
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	dis[x1][y1] = 0;
	deque<Node> q;
	q.push_front({x1,y1,0});
	while(q.size()){
		auto [x,y,t] = q.front();
		q.pop_front();
		if(st[x][y]) continue;
		st[x][y] = 1;
		for(int i=0;i<4;i++){
			int nx = x + dx[i],ny = y + dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny]) continue;
			if(a[nx][ny] == '.'){
				dis[nx][ny] = min(dis[nx][ny],t);
				q.push_front({nx,ny,t});
			}else{
				dis[nx][ny] = min(dis[nx][ny],t+1);
				q.push_back({nx,ny,t+1});
				nx += dx[i],ny += dy[i];
				if(nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny]) continue;
				dis[nx][ny] = min(dis[nx][ny],t+1);
				q.push_back({nx,ny,t+1});
			}
		}
	}
	cout << dis[x2][y2] << endl;
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