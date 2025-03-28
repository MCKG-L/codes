#include <iostream>
#include <cstring>
#include <deque>
using namespace std;
const int N = 2010;
int a[N][N];
struct node{
    int x,y,l,r;
};
bool st[N][N];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m,l,r,sx,sy,ans;
void bfs(){
    deque<node> q;q.push_front({sx,sy,l,r});
    ans = 1;st[sx][sy] = 1;
    while(q.size()){
        node f = q.front();q.pop_front();
        int x = f.x,y = f.y,nl = f.l,nr = f.r;
        for(int i=0;i<4;i++){
            int nx = x + dx[i],ny = y + dy[i];
            if(st[nx][ny] || a[nx][ny] || nx<1 || nx>n || ny<1 || ny>m) continue;
            if(i == 0 || i == 1){//上 下
                q.push_front({nx,ny,nl,nr});
                st[nx][ny] = 1;ans++;
            }else if(i == 2){//左
                if(nl < 1) continue;
                q.push_back({nx,ny,nl-1,nr});
                st[nx][ny] = 1;ans++;
            }else{//右
                if(nr < 1) continue;
                q.push_back({nx,ny,nl,nr-1});
                st[nx][ny] = 1;ans++;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    cin >> sx >> sy;
    cin >> l >> r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;cin >> c;
            a[i][j] = c == '.' ? 0 : 1;
        }
    }
    bfs();
    cout << ans << endl;
    return 0;
}