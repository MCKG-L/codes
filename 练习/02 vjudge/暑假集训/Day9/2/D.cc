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
bool f = 0;
void dfs(int x,int y,int k){
    if(x == h-1 && y == w-1){
        f = 1;return;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(st[nx][ny] || s[k] != g[nx][ny]) continue;
        st[nx][ny] = 1;dfs(nx,ny,(k+1)%5);
    }
}
void solve(){
    cin >> h >> w;
    for(int i=0;i<h;i++) cin >> g[i];
    if(g[0][0] != 's'){
        cout << "No" << endl;
        return;
    }
    dfs(0,0,1);
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}