#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
char g[N][N];
bool st[N][N];
void bfs(int x,int y){
    queue<PII> que;
    que.push({x,y});
    st[x][y] = 1;
    while(que.size()){
        PII t = que.front();que.pop();
        int x = t.first,y = t.second;
        for(int i=x-1;i<=x+1;i++){
            for(int j=y-1;j<=y+1;j++){
                if(i == x && j == y) continue;
                if(i < 0 || i >= n || j < 0 || j >= m) continue;
                if(st[i][j] || g[i][j] == '.') continue;
                que.push({i,j});st[i][j] = 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> g[i];
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(st[i][j] || g[i][j] == '.') continue;
            bfs(i,j);
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}