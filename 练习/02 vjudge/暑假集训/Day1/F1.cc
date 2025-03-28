#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> p[n+1];
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
    int x = m - cnt,y = m / x - 1;
    cout << x <<  ' ' << y << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}