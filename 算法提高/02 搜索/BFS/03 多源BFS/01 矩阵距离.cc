#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char a[N][N];
bool st[N][N];
int dis[N][N];
int n,m;
queue<PII> que;
void bfs(){
    while(que.size()){
        PII t = que.front();que.pop();
        int x = t.first,y = t.second;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(st[nx][ny]) continue;
            if(dis[nx][ny] > dis[x][y] + 1){
                dis[nx][ny] = dis[x][y] + 1;
                que.push({nx,ny});st[nx][ny] = true;
            }
        }
    }
}
int main()
{
    memset(dis,0x3f,sizeof dis);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == '1'){
                que.push({i,j});
                dis[i][j] = 0;st[i][j] = 1;
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dis[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}