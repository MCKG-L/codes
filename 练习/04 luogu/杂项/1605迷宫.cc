#include <bits/stdc++.h>
using namespace std;
const int N = 12;
bool vis[N][N];
int a[N][N];
int n,m,t,sx,sy,fx,fy;
int ans;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void dfs(int x,int y){
    if(x == fx && y == fy){
        ans++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!=-1&&!vis[nx][ny]){
            vis[nx][ny] = true;//标记
            dfs(nx,ny);
            vis[nx][ny] = false;//清除标记
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy;
    cin >> fx >> fy;
    for(int i=0;i<t;i++){
        int x,y;
        cin >> x >> y;
        a[x][y] = -1;
    }
    vis[sx][sy] = 1;//初始化
    dfs(sx,sy);
    cout << ans;
    return 0;
}