#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> g(n + 1,vector<char>(m + 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> g[i][j];
    }
    vector<vector<int>> dis(n + 1,vector<int>(m + 1,inf));
    vector<vector<bool>> st(n + 1,vector<bool> (m + 1,false));
    auto bfs = [&]()->void{
        deque<PII> q;
        q.push_back({1,1});
        dis[1][1] = 0;
        while(q.size()){
            auto [x,y] = q.front();q.pop_front();
            if(x == n && y == m) return;
            if(st[x][y]) continue;
            st[x][y] = 1;
            for(int i=0;i<4;i++){
                int nx = x + dx[i],ny = y + dy[i];
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if(st[nx][ny]) continue;
                dis[nx][ny] = min(dis[nx][ny],dis[x][y] + 1);
                if(dis[nx][ny] <= 1) q.push_back({nx,ny});
            }
            int nx = x,ny = y;
            if(g[x][y] == 'U') nx -= 1;
            if(g[x][y] == 'D') nx += 1;
            if(g[x][y] == 'L') ny -= 1;
            if(g[x][y] == 'R') ny += 1;
            if(nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny]) continue;
            dis[nx][ny] = min(dis[nx][ny],dis[x][y]);
            if(dis[nx][ny] <= 1) q.push_front({nx,ny});
        }
    };
    bfs();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << dis[i][j] << " \n"[j == m];
    //     }
    // }
    // cout << dis[n][m] << endl;
    cout << (dis[n][m] <= 1 ? "YES" : "NO") << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}