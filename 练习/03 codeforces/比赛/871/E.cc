#include <iostream>
#define endl '\n'
using namespace std;
const int N = 1001;
int n,m;
int a[N][N];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int dfs(int x,int y){
    if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 0) return 0;

    int res = a[x][y];
    a[x][y] = 0;
    for(int i=0;i<4;i++){
        res += dfs(x+dx[i],y+dy[i]);
    }
    return res;
}

void solve(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(ans,dfs(i,j));
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