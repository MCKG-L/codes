#include <iostream>
#include <queue>
using namespace std;
const int N = 510;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int n,m;
string s;
char a[N][N];
bool st[N][N];

struct Node{
    int x,y;
    int t;
};
bool bfs(){
    queue<Node> que;
    que.push({1,1,1});
    while(que.size()){
        Node f = que.front();
        que.pop();
        int x = f.x,y = f.y,t = f.t;
        if(x == n && y == m) return true;
        if(st[x][y]) continue;
        st[x][y] = true;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(st[nx][ny] || a[nx][ny] != s[t]) continue;
            que.push({nx,ny,(t+1)%5});
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i] + 1;
    s = "snuke";
    if(a[1][1] != s[0]){
        puts("No");
        return 0;
    }
    if(bfs()) puts("Yes");
    else puts("No");
    return 0;
}