#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int g[N][N];
int st[N][N];
int n;
int bfs(int sx,int sy,bool &f1,bool &f2){
    queue<PII> que;
    que.push({sx,sy});
    st[sx][sy] = true;
    while(que.size()){
        PII t = que.front();que.pop();
        int x = t.first,y = t.second;
        for(int i=x-1;i<=x+1;i++){
            for(int j=y-1;j<=y+1;j++){
                if(i < 0 || i >= n || j < 0 || j >= n) continue;
                if(g[i][j] > g[x][y]) f1 = true;
                if(g[i][j] < g[x][y]) f2 = true;
                if(!st[i][j] && g[i][j] == g[x][y]){
                    que.push({i,j});st[i][j] = true;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> g[i][j];
        }
    }
    int ans1 = 0,ans2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(st[i][j]) continue;
            bool f1 = false,f2 = false;
            int t = bfs(i,j,f1,f2);
            if(!f1) ans1 ++;
            if(!f2) ans2 ++;
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}