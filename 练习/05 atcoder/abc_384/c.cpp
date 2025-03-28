#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<char>> g(n + 1,vector<char>(m + 1));
    queue<PII> q;
    vector<vector<bool>> st(n + 1,vector<bool>(m + 1,false));
    vector<vector<int>> dis(n + 1,vector<int>(m + 1,inf));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> g[i][j];
            if(g[i][j] == 'H'){
                q.push({i,j});
                dis[i][j] = 0;
                st[i][j] = 1;
            }
        }
    }
    while(q.size()){
        auto [x,y] = q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i],ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(st[nx][ny] || g[nx][ny] == '#') continue;
            st[nx][ny] = 1;
            q.push({nx,ny});
            dis[nx][ny] = dis[x][y] + 1;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dis[i][j] <= k) ans ++;
        }
    }
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