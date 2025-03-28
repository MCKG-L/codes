#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1010,inf = 3e18;
bool st[N][N][10];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
struct Node{
    int x,y,op,t;
};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<string> g(n + 1);
    for(int i=1;i<=n;i++){
        cin >> g[i];
        g[i] = ' ' + g[i];
    }
    int sx,sy,ex,ey;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j] == 'S'){
                sx = i,sy = j;
            }
            if(g[i][j] == 'G'){
                ex = i,ey = j;
            }
        }
    }
    queue<Node> q;
    for(int i=0;i<4;i++){
        int nx = sx + dx[i],ny = sy + dy[i];
        q.push({sx,sy,i,0});
        st[sx][sy][i] = 1;
    }
    while(q.size()){
        auto [x,y,op,t] = q.front();
        q.pop();
        if(x == ex && y == ey){
            cout << t << endl;
            return;
        }
        string ops = (op == 0 || op == 1) ? "23" : "01";
        for(auto c : ops){
            c = c - '0';
            int nx = x + dx[c],ny = y + dy[c];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(st[nx][ny][c] || g[nx][ny] == '#') continue;
            q.push({nx,ny,c,t+1});
            st[nx][ny][c] = 1;
        }
    }
    cout << -1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}