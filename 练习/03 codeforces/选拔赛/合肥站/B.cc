#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;

void solve(){
    int n,m;
    cin >> m >> n;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    set<int> s;
    queue<int> q;
    vector<int> ans(m+1);
    int lst = 0;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(!s.count(a[i][j])){
                q.push(a[i][j]);
                s.insert(a[i][j]);
            }
        }
        if(s.size() == j){
            while(q.size()){
                int x = q.front();
                q.pop();
                ans[x] = m - lst - 1;
            }
            lst = j;
        }
    }
    for(int i=1;i<=m;i++) cout << ans[i] << ' ';
    cout << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}