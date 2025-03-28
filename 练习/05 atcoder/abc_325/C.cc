#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
char s[N][N];
int n,m;
bool st[N][N];
void bfs(int sx,int sy){
    st[sx][sy] = 1;
    queue<PII> q;
    q.push({sx,sy});
    while(q.size()){
        auto [x,y] = q.front();q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nx = x + i,ny = y + j;
                if(st[nx][ny] || s[nx][ny] != '#') continue;
                q.push({nx,ny});st[nx][ny] = 1;
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> s[i] + 1;
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(st[i][j] || s[i][j] == '.') continue;
            ans ++;bfs(i,j);
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}