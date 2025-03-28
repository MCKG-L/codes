#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 510;
int g[N][N];
int dis[N];
bool st[N];
int n,m;
/*
5 5
1 2 3
3 1 4
2 4 6
4 2 1
1 4 7
*/
void Dijkstra(){
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    for(int i=0;i<n;i++){
        //在未确定最短距离的点中找到距起点最小的点
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!st[j] && (t == -1 || dis[j] < dis[t])) t = j;
        }
        st[t] = true;
        //更新
        for(int j=1;j<=n;j++) dis[j] = min(dis[j],dis[t] + g[t][j]);
    }
}
void solve(){
    cin >> n >> m;
    memset(g,0x3f,sizeof g);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b],c);
    }
    Dijkstra();
    if(dis[n] != 0x3f3f3f3f) cout << dis[n] << endl;
    else cout << -1 << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}