#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef pair<int,int> PII;
const int N = 210;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m;
struct Node{
    int x,y;
    int op;
    bool operator <(Node p) const{
        if(x*N+y == p.x*N+p.y) return op < p.op;
        return x * N + y < p.x * N + p.y;
    }
};
map<Node,int> mp;
int g[N][N];
bool st[N][N];
void dfs(int x,int y,int op){
    st[x][y] = 1;
    int nx = x + dx[op],ny = y + dy[op];
    while(g[nx][ny] == 0){
        st[nx][ny] = 1;
        nx += dx[op],ny += dy[op];
    }
    nx -= dx[op],ny -= dy[op];
    for(int i=0;i<4;i++){
        if(i == op) continue;
        if(mp.count({nx,ny,i})) continue;
        int sx = nx + dx[i];
        int sy = ny + dy[i];
        if(g[sx][sy] == 1) continue;
        mp[{nx,ny,i}] = 1;
        dfs(nx,ny,i);
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;cin >> c;
            g[i][j] = (c == '.' ? 0 : 1);
        }
    }
    mp[{2,2,1}] = 1;mp[{2,2,3}] = 1;
    dfs(2,2,3);dfs(2,2,1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(st[i][j]) ans ++;
            // cout << st[i][j] << ' ';
        }
        // cout << endl;
    }
;
    cout << ans << endl;
    return 0;
}