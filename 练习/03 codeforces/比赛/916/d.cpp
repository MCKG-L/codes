#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n;
    cin >> n;
    vector<PII> a(n),b(n),c(n);
    for(int i=0;i<n;i++) {
        int x;cin >> x;
        a[i] = make_pair(x,i);
    }
    for(int i=0;i<n;i++) {
        int x;cin >> x;
        b[i] = make_pair(x,i);
    }
    for(int i=0;i<n;i++) {
        int x;cin >> x;
        c[i] = make_pair(x,i);
    }
    sort(a.begin(),a.end(),greater<PII>());
    sort(b.begin(),b.end(),greater<PII>());
    sort(c.begin(),c.end(),greater<PII>());
    // cout << a[0].first << ' ' << a[1].first << ' ' << a[2].first << endl;
    int pos[10];
    int ans = 0;
    // for(int i=0;i<=9;i++) pos[i] = -1;
    function<void(int)> dfs = [&](int u)->void{
        if(u > 2){
            int p1 = a[pos[0]].second,p2 = b[pos[1]].second,p3 = c[pos[2]].second;
            if(p1 == p2 || p1 == p3 || p2 == p3) return;
            ans = max(ans,a[pos[0]].first + b[pos[1]].first + c[pos[2]].first);
            return;
        }
        for(int i=0;i<3;i++){
            pos[u] = i;
            dfs(u + 1);
        }
    };
    dfs(0);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}