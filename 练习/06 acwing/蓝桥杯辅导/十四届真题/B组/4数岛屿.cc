#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 55;
typedef pair<int,int> PII;
vector<vector<bool>> vis(N,vector<bool>(N,false)),st(N,vector<bool>(N,false));
char s[N][N];
int n,m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool bfs1(int sx,int sy){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++) vis[i][j] = 0;
    }
    queue<PII> q;
    q.push({sx,sy});
    while(q.size()){
        auto [x,y] = q.front();q.pop();
        for(int i=x-1;i<=x+1;i++){
            for(int j=y-1;j<=y+1;j++){
                if(i < 0 || i >= n || j < 0 || j >= m) return 1;
                if(vis[i][j]) continue;vis[i][j] = 1;
                if(!st[i][j] && s[i][j] == '0') q.push({i,j});
            }
        }
    }
    return 0;
}
void bfs(int sx,int sy){
    queue<PII> q;
    q.push({sx,sy});
    st[sx][sy] = true;
    while(q.size()){
        auto [x,y] = q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i],ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || st[nx][ny]) continue;
            if(s[nx][ny] == '0') continue;
            q.push({nx,ny});st[nx][ny] = 1;
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            st[i][j] = vis[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++) cin >> s[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j] == '0' || st[i][j]) continue;
            st[i][j] = 1;
            bfs(i,j);
            if(bfs1(i,j)) ans ++;
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}