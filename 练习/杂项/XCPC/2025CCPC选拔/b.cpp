#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353,inf = 1e18;
const int N = 2e5 + 10,M = 1e9 + 10;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n + 2,vector<int>(m + 2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;cin >> c;
            g[i][j] = c == 'B' ? 1 : 0;
        }
    }
    bool ok = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j] == 1){
                for(int k=0;k<4;k++){
                    int nx = i + dx[k],ny = j + dy[k];
                    if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                    if(g[nx][ny] == 1){
                        ok = 0;
                        cout << "No" << endl;
                        return;
                    }
                }
            }
        }
    }
    int x = n / 2;
    bool ok = 0;
    for(int j=1;j<=m;j++){
        int cnt = 0;
        cnt += g[x][j] + g[x][j+1] + g[x+1][j] + g[x+1][j+1];
        if(cnt >= 2){
            break;
        }
    }
    int y = m / 2;
    
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