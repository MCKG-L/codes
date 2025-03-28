#include <iostream>
using namespace std;
const int N = 20;
bool a[N],b[N],c[N],d[N];
int ans,n;
char g[N][N];
void dfs(int x,int y,int s){
    if(y == n) y = 0,x ++;
    if(x == n){
        if(s == n){
            ans++;
            for(int i=0;i<n;i++) puts(g[i]);
            cout << endl;
        }
        return;
    }
    //不放
    dfs(x,y+1,s);
    //放
    if(!a[x]&&!b[y]&&!c[x+y]&&!d[x-y+n]){
        a[x] = b[y] = c[x+y] = d[x-y+n] = 1;
        g[x][y] = 'Q';
        dfs(x,y+1,s+1);
        a[x] = b[y] = c[x+y] = d[x-y+n] = 0;
        g[x][y] = 'X';
    }
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j] = 'X';
        }
    }
    dfs(0,0,0);
    cout << ans << endl;
    return 0;
}