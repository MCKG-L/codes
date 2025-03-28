#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int a[N][N];
bool st[N][N];
int n,m;
long long ans;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
long long bfs(int x,int y){
    long long ans = a[x][y];
    queue<PII> que;
    que.push({x,y});
    while(que.size()){
        PII t = que.front();que.pop();
        int x = t.first,y = t.second;
        for(int i=0;i<4;i++){  
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(st[nx][ny] || !a[nx][ny]) continue;
                ans += a[nx][ny];
                st[nx][ny] = true;
                que.push({nx,ny});
            }
        }
    }
    return ans;
}
void solve(){
    memset(st,0,sizeof st);
    ans = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(st[i][j] || !a[i][j]) continue;
            st[i][j] = true;
            
            ans = max(ans,bfs(i,j));
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}