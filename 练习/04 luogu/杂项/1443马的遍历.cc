#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int a[N][N];
int n,m,x,y;
struct p{
    int x,y,t;
};
int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
queue<p> que;
int main()
{
    cin >> n >> m >> x >> y;
    que.push((p){x,y,0});
    memset(a,-1,sizeof(a));
    a[x][y] = 0;
    while(!que.empty()){
        p f = que.front();
        que.pop();
        for(int i=0;i<8;i++){
            int nx = f.x + dx[i];
            int ny = f.y + dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]==-1){
                a[nx][ny] = f.t + 1;
                que.push((p){nx,ny,f.t+1});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%-5d",a[i][j]);
        }
        cout << endl;
    }
    return 0;
}