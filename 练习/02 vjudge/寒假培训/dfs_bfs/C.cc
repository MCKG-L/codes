#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
// #include <bits/stdc++.h>
using namespace std;
const int N = 410;
int a[N][N];
int dx[8] = {-2,-2,-1,-1,2,2,1,1};
int dy[8] = {1,-1,2,-2,1,-1,2,-2};
struct point{
    int x,y,t;
};
queue<point> que;
int n,m,sx,sy;
int main()
{
    memset(a,-1,sizeof(a));
    cin >> n >> m >> sx >> sy;
    a[sx][sy] = 0;
    //bfs
    que.push((point){sx,sy,0});
    while(!que.empty()){
        point f = que.front();
        que.pop();
        for(int i=0;i<8;i++){
            int nx = f.x + dx[i];
            int ny = f.y + dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]==-1){
                a[nx][ny] = f.t + 1;
                que.push((point){nx,ny,f.t+1});
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