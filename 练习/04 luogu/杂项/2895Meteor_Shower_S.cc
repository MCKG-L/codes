#include <iostream>
#include <queue>
#include <string.h>
// #include <bits/stdc++.h>
using namespace std;
const int N = 310;
struct p{
    int x,y,t;
}f;
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
bool vis[N][N];
int s[N][N];//陨石到达时间
queue<p> que;
void fun(int x,int y,int t){
    for(int i=0;i<5;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && (s[nx][ny] == -1 || s[nx][ny] > t)){
            s[nx][ny] = t;
        }
    }
}
void bfs(int n){
    que.push((p){0,0,0});
    vis[0][0] = 1;
    int mask = 1;
    while(!que.empty()){
        f = que.front();
        que.pop();
        int x = f.x,y = f.y;
        if(x >= 0 && y >= 0 && s[x][y] == -1){
            cout << f.t;
            mask = 0;
            return;
        }
        for(int i=1;i<5;i++){
            int nx = f.x + dx[i];
            int ny = f.y + dy[i];
            int nt = f.t + 1;
            if(nx >= 0 && ny >= 0 && !vis[nx][ny] && (nt < s[nx][ny] || s[nx][ny] == -1)){
                vis[nx][ny] = 1;
                que.push((p){nx,ny,f.t+1});
            }
        }
    }
    if(mask) cout << -1 << endl;
}
int main()
{
    int n;cin >> n;
    memset(s,-1,sizeof(s));
    for(int i=0;i<n;i++){
        // auto &[x,y,t] = a[i];
        int x,y,t;
        cin >> x >> y >> t;  
        fun(x,y,t);    
    }
    bfs(n);
    return 0;
}

