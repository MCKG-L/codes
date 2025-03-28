#include <iostream>
#include <cstring>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 510;
int n,m;
char g[N][N];
int st[N][N];
int dis[N][N];
int bfs(){
    memset(st,0,sizeof st);
    memset(dis,0x3f,sizeof dis);
    deque<PII> q;
    char cs[5] = "\\/\\/";//注意'\'是转移字符，需要用"\\"
    int dx[4] = {-1,-1,1,1},dy[4] = {-1,1,1,-1};
    int ix[4] = {-1,-1,0,0},iy[4] = {-1,0,0,-1};
    q.push_back({0,0});
    dis[0][0] = 0;
    while(q.size()){
        PII t = q.front();
        q.pop_front();
        int x = t.first,y = t.second;
        if(x == n && y == m) return dis[n][m];
        if(st[x][y]) continue;
        st[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx > n || ny < 0 || ny > m) continue;
            int ia = x + ix[i],ib = y + iy[i];
            int w = cs[i] == g[ia][ib] ? 0 : 1;
            if(dis[nx][ny] > dis[x][y] + w){
                dis[nx][ny] = dis[x][y] + w;
                if(w == 1) q.push_back({nx,ny});
                else q.push_front({nx,ny});
            }
        }
    }
    return -1;
}
void solve(){
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> g[i];
    if(n + m & 1) cout << "NO SOLUTION" << endl;
    else cout << bfs() << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}