#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int unsigned long long
typedef pair<pair<int,int>,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
ll dx[] = {-1,1,0,0};
ll dy[] = {0,0,-1,1};
struct Node{
    int val,x,y;
    bool operator<(const Node &p)const{
        return val > p.val;
    }
};
void solve(){
    int n,m,sx,sy,k;
    cin >> n >> m >> k;
    cin >> sx >> sy;
    vector<vector<int>> g(n + 1,vector<int>(m + 1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> g[i][j];
    }
    priority_queue<Node> heap;
    vector<vector<bool>> st(n + 1,vector<bool>(m + 1,false));
    st[sx][sy] = 1;
    int sum = g[sx][sy];
    for(int i=0;i<4;i++){
        int nx = sx + dx[i],ny = sy + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        st[nx][ny] = 1;
        heap.push({g[nx][ny],nx,ny});
    }
    while(heap.size()){ 
        auto [val,x,y] = heap.top();heap.pop();
        // if(val < (sum + k - 1) / k){  //爆long long 乘法改除法
            if((i128)val * k < sum){ //或者使用__int128
            for(int i=0;i<4;i++){
                int nx = x + dx[i],ny = y + dy[i];
                if(nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny]) continue;
                st[nx][ny] = 1;
                heap.push({g[nx][ny],nx,ny});
            }
            sum += val;
        }else{
            cout << sum << endl;
            return;
        }
    }
    cout << sum << endl;
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