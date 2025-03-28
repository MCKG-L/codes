#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,pair<int,int>> PIP;
const int N = 1e3 + 10;
// struct Node{
//     int val;
//     int x,y;
//     bool operator< (const Node p) const{
//         return p.val < val;
//     }
// };
int g[N][N];
int n,m,sx,sy;
int mx;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
bool check(int mid){
    vector<vector<bool>> st(n+10,vector<bool> (m+10,false));
    int sum = mid;
    priority_queue<PIP,vector<PIP>,greater<PIP>> heap;
    heap.push({0,{sx,sy}});
    st[sx][sy] = 1;
    while(heap.size()){
        auto [v,t] = heap.top();
        heap.pop();
        auto [x,y] = t;
        if(x != sx || y != sy){
            if(sum >= mx) return 1;
            else if(sum < v){
            return 0;
            }
            sum += v;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(st[nx][ny]) continue;
            heap.push({g[nx][ny],{nx,ny}});
            st[nx][ny] = 1;
        }
    }
    return 1;
}
void solve(){
    cin >> n >> m >> sx >> sy;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> g[i][j];
            mx = max(mx,g[i][j]);
        }
    }
    int l = g[sx][sy],r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(l == g[sx][sy]){
        cout << "No cheating need.\n" << endl;
    }else{
        cout << l << endl;
    }
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}