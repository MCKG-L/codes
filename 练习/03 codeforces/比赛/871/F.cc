#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const int N = 1005;
vector<int> p[N];
int n,m;
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) p[i].clear();
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(p[i].size() == 1) cnt ++;
    }
    int x = m - cnt;
    int y = m / x - 1;
    cout << x << ' ' << y << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}