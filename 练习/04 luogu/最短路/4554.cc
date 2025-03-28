#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 510;
char g[N][N];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool st[N][N];
int n,m;
int sx,sy,fx,fy;
struct P{
    int x,y,t;
}f;
void bfs(int x,int y){
    // if(x == fx && y == fy) return ans;
    queue<P> q;
    q.push((P){x,y,0});
    st[x][y] = 1;
    while(q.size()){
        f = q.front();q.pop();
        if(f.x == fx && f.y == fy){
            return;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!st[nx][ny] && nx>=0&&nx<n && ny>=0&&ny<m){
                // if(g[x][y] != g[nx][ny]
                st[nx][ny] = 1;
                int w = g[nx][ny] == g[x][y] ? 0 : 1;
                q.push((P){nx,ny,f.t+w});
            }
        }
    }
}
int main()
{
    while(1){
        memset(st,0,sizeof st);
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> g[i][j];
            }
        }
        cin >> sx >> sy >> fx >> fy;
        bfs(sx,sy);
        cout << f.t << endl;
    }
}