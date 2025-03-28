#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
const int N = 55;
int g[N][N];
bool st[N][N];
int n,m;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int bfs(int sx,int sy){
    queue<PII> que;
    int ans = 0;
    que.push({sx,sy});
    st[sx][sy] = true;
    while(que.size()){
        PII t = que.front();
        que.pop();ans ++;
        int x = t.first,y = t.second;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(st[nx][ny]) continue;
            if(g[x][y] >> i & 1) continue;
            que.push({nx,ny});
            st[nx][ny] = true;
        }
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> g[i][j];
        }
    }
    int cnt = 0,ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(st[i][j]) continue;
            ans = max(ans,bfs(i,j));
            cnt ++;
        }
    }
    cout << cnt << '\n' << ans << endl;
    return 0;
}