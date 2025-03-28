#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
int a[N][N];
bool st[N][N];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int bfs(int sx,int sy){
    st[sx][sy] = 1;
    queue<PII> q;
    q.push(make_pair(sx,sy));
    int res = 0;
    while(q.size()){
        PII k = q.front();q.pop();
        int x = k.first,y = k.second;
        res += a[x][y];
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(st[nx][ny] || a[nx][ny] == 0) continue;
            st[nx][ny] = 1;
            q.push(make_pair(nx,ny));
        }
    }
    return res;
}
void solve(){
    memset(st,false,sizeof st);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(st[i][j] || !a[i][j]) continue;
            ans = max(ans,bfs(i,j));
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}