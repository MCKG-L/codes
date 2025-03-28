#include <iostream>
#include <algorithm>
using namespace std;
int a[10][10];
bool vis[10][10];
int dx[5] = {-1,1,0,0,0};
int dy[5] = {0,0,-1,1,0};
int ans = 1e9;
bool check(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(a[i][j] != 0) return false;
        }
    }
    return true;
}
void func(int x,int y){
    for(int i=0;i<5;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        a[nx][ny] ^= 1;
    }
}
void dfs(int t){
    if(t > ans) return;
    if(check()){
        ans = min(ans,t);
        return;
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(vis[i][j] == 1) continue;
            vis[i][j] = 1;
            func(i,j);
            dfs(t+1);
            //回溯
            vis[i][j] = 0;
            func(i,j);
        }
    }
}
int main()
{
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin >> a[i][j];
        }
    }
    dfs(0);
    cout << ans << '\n';
    return 0;
}