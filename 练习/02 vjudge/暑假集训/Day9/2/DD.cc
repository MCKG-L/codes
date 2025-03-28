#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 510;
char g[N][N];
bool st[N][N];
int h,w;
string s = "snuke";
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool bfs(){
    queue<array<int,3>> q;
    q.push({0,0,1});
    while(q.size()){
        auto &[x,y,t] = q.front();q.pop();
        if(x == h-1 && y == w-1) return 1;
        if(st[x][y]) continue;
        st[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(st[nx][ny] || s[t] != g[nx][ny]) continue;
            q.push({nx,ny,(t+1)%5});
        }
    }
    return 0;
}
void solve(){
    cin >> h >> w;
    for(int i=0;i<h;i++) cin >> g[i];
    if(g[0][0] != 's') cout << "No" << endl;
    else cout << (bfs() ? "Yes" : "No") << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}