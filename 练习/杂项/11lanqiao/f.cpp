#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int inf = 1e9;
struct Node{
	int x,y;
	int t;
};
int dx[] = {-1,0,1};
int dy[] = {0,1,0};
void solve(){
	string s1,s2;
	cin >> s1 >> s2;
	int n = s1.size();
	s1 = ' ' + s1,s2 = ' ' + s2;
	vector<string> a(3);
	a[1] = s1,a[2] = s2;
	vector<vector<bool>> st(3,vector<bool>(n + 1));
	vector<vector<int>> dis(3,vector<int>(n+1,inf));
	deque<Node> q;
	for(int i=1;i<=n;i++){
		if(a[2][i] == '#' || a[1][i] == '#'){
			Node f;
			f.x= 1,f.y= i,f.t= 0;
			if(a[1][i] == '#') q.push_back(f);
			f.x= 2;
			if(a[2][i] == '#') q.push_back(f);
			break;
		}
	}
	if(q.size() == 0){
		cout << 0 << endl;
		return;
	}
	while(q.size()){
		Node f = q.front();q.pop_front();
		int x = f.x,y= f.y,t = f.t;
		for(int i=0;i<3;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 1 || nx > 2 || ny < 1 || ny > n) continue;
			if(st[nx][ny]) continue;
			st[nx][ny] = 1;
			int v = a[nx][ny] == '.' ? 1 : 0;
			dis[nx][ny] = t + v;
			Node f;
			f.x = nx,f.y= ny,f.t= t + v;
			if(v == 1){
				
				q.push_back(f);
			}else{
				q.push_front(f);
			}
		}
	}
	int ans = inf;
	for(int i=n;i>=1;i--){
		if(a[1][i] == '#' || a[2][i] == '#'){
			ans = min(ans,min(dis[1][i],dis[2][i]));
			break;
		}
	}
	cout << ans << endl;
} 
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	#ifdef LOCAL
		freopen("C:\\Users\\lanqiao\\text.in","r",stdin);
	#endif
	int T = 1;
//	cin >> T;
	while(T --) solve();
	return 0;
}
