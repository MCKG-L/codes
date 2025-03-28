#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 510;
int dis[N][N],a[N][N];
bool st[N][N];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m,sx,sy,fx,fy;
//相当于堆优化Dijkstra的再优化，用deque代替优先队列
void bfs(){
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    dis[sx][sy] = 0;
    deque<PII> q;
    q.push_front({sx,sy});
    while(q.size()){
        PII t = q.front();q.pop_front();
        int x = t.first,y = t.second;
        if(st[x][y]) continue;
        st[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            int w = a[x][y] == a[nx][ny] ? 0 : 1;
            if(dis[nx][ny] > dis[x][y] + w){
                dis[nx][ny] = dis[x][y] + w;
                if(w == 0) q.push_front({nx,ny});
                else q.push_back({nx,ny});
            }
        }
    }
}
int main(){
    while(1){
        cin >> n >> m;
        if(m == 0 && n == 0) break;
        char c;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> c;
                a[i][j] = c == '@' ? 1 : 0;
            }
        }
        cin >> sx >> sy >> fx >> fy;
        sx++,sy++,fx++,fy++;
        bfs();
        cout << dis[fx][fy] << endl;
    }
    return 0;
}
