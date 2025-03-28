#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 155;
int dx[] = {-1,-2,-2,-1,1,2,2,1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};
struct Node{
    int x,y;
    int t;
};
int sx,sy,n,m;
char g[N][N];
bool st[N][N];
int bfs(int sx,int sy){
    queue<Node> que;
    que.push({sx,sy,0});
    st[sx][sy] = true;
    while(que.size()){
        Node f = que.front();que.pop();
        for(int i=0;i<8;i++){
            int x = f.x + dx[i];
            int y = f.y + dy[i];
            if(x <= 0 || x > n || y <= 0 || y > m) continue;
            if(st[x][y] || g[x][y] == '*') continue;
            if(g[x][y] == 'H') return f.t + 1;
            que.push({x,y,f.t+1});
        }
    }
}
int main()
{
    cin >> m >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> g[i][j];
            if(g[i][j] == 'K') sx = i,sy = j;
        }
    }
    cout << bfs(sx,sy) << endl;
    return 0;
}