#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
const int N = 1005;
char a[N][N];
struct P{
    int x,y;
}f;
queue<P> que;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool st[N][N];
int d[N][N];
int k,n,m,ans=1e9;
int sx,sy,fx,fy;
int dis(int x,int y){
    return abs(fx-x)+abs(fy-y);
}
void bfs(){
    que.push({sx,sy});
    // st[sx][sy] = 1;
    while(que.size()){
        f = que.front();que.pop();
        if(st[f.x][f.y]) continue;
        ans = min(ans,dis(f.x,f.y));
        if(f.x == fx && f.y == fy) break;
        st[f.x][f.y] = true;
        for(int i=0;i<4;i++){
            int nx = f.x + dx[i];
            int ny = f.y + dy[i];
            if(st[nx][ny] || a[nx][ny] == '#') continue;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            d[nx][ny] = d[f.x][f.y] + 1;
            if(d[nx][ny] > k) continue;
            que.push({nx,ny});
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;cin.get(c);
            if(c == '\n'){j--;continue;}
            a[i][j] = c;
            if(c == 'S') sx = i,sy = j;
            if(c == 'T') fx = i,fy = j;
        }
    }
    bfs();
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
    return 0;
}