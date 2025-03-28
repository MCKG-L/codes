#include <iostream>
#include <queue>
#include <cstring>
#define IOS     ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define endl    '\n'
#define lx      first
#define ly      second
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int g[N][N];
PII p[N][N];
int n;
void bfs(int sx,int sy){
    queue<PII> que;
    que.push({sx,sy});
    memset(p,-1,sizeof p);
    while(que.size()){
        PII t = que.front();que.pop();
        int x = t.lx,y = t.ly;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(p[nx][ny].lx != -1 || g[nx][ny]) continue;
            que.push({nx,ny});p[nx][ny] = {x,y};
        }
    }
}
int main()
{
    IOS;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    bfs(n-1,n-1);
    PII ed(0,0);
    while(true){
        int x = ed.lx,y = ed.ly;
        cout << x << ' ' << y << endl;
        if(x == n-1 && y == n-1) break;
        ed = p[x][y];
    }
    return 0;
}