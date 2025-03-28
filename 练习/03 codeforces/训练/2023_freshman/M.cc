#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 31;
int sx,sy,fx,fy,nx,ny;
struct Point{
    int x,y;
};
struct Node{
    Point a,b;
    int t;
};
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool st[N][N][N][N];
int g[N][N];
bool check(int x,int y){
    if(x >= 1 && x <= 30 && y >= 1 && y <= 30 && g[x][y] == 0) return 1;
    return 0;
}
int bfs(){
    queue<Node> que;
    st[sx][sy][nx][ny] = 1;
    que.push({{sx,sy},{nx,ny},0});
    while(que.size()){
        auto [a,b,now] = que.front();que.pop();
        int ax = a.x,ay = a.y;
        int bx = b.x,by = b.y;
        // if(st[ax][ay][bx][by]) continue;
        if(bx == fx && by == fy){
            return now;
        }
        for(int i=0;i<4;i++){
            int x = ax + dx[i],y = ay + dy[i];
            if(check(x,y) == 0) continue;
            if(x == bx && y == by){
                if(check(bx + dx[i],by + dy[i])){
                    if(st[x][y][bx+dx[i]][by+dy[i]] == 0)
                    que.push({{x,y},{bx+dx[i],by+dy[i]},now+1}),
                    st[x][y][bx+dx[i]][by+dy[i]] = 1;
                }
            }else if(st[x][y][bx][by] == 0){
                que.push({{x,y},{bx,by},now+1});
                st[x][y][bx][by] = 1;
            }
        }
    }
    return -1;
}
void solve(){
    cin >> sx >> sy >> fx >> fy >> nx >> ny;
    int m;cin >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    cout << bfs() << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}