#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 510;
char a[N][N];
bool st[N][N];
string s;
int n,m;
bool flag = false;
void dfs(int x,int y,int t){
    if(x == n && y == m){
        flag = true;
        return;
    }
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(st[nx][ny] || a[nx][ny] != s[t]) continue;
        st[nx][ny] = 1;
        dfs(nx,ny,(t+1)%5);
    }
}
int main()
{
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    if(a[1][1] != 's'){
        cout << "No" << endl;
        return 0;
    }
    s = "snuke";
    dfs(1,1,1);
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}