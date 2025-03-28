#include <iostream>
using namespace std;
const int N = 10;
int n,m,k,sx,sy,fx,fy;
int a[N][N];
bool vis[N][N];
int ans;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void dfs(int x,int y){
    if(x == fx && y == fy){
        ans ++;
        return;
    }
    // vis[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!a[nx][ny]&&!vis[nx][ny]){
        	vis[nx][ny] = 1;//标记
            dfs(nx,ny);
            vis[nx][ny] = 0;//回溯 清除标记
        }
        
    }
}
int main()
{
    cin >> n >> m >> k;
    cin >> sx >> sy >> fx >> fy;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    vis[sx][sy] = 1;
    dfs(sx,sy);
    cout << ans;
    return 0;
}