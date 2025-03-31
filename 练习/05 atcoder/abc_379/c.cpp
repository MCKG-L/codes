#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e9;
void solve(){
    int n,m;cin >> n >> m;
    int sum = 0;
    vector<int> a(m + 1),b(m + 1);
    for(int i=1;i<=m;i++) cin >> a[i];
    vector<PII> p(m + 2);
    for(int i=1;i<=m;i++){
        int x;cin >> x;
        p[i] = {a[i],x};
        sum += x;
    }
    if(sum != n){
        cout << -1 << endl;
        return;
    }
    sort(p.begin()+1,p.begin()+1+m);
    int ans = 0;
    for(int i=1;i<m;i++){
        auto &[x,y] = p[i];
        auto &[x1,y1] = p[i+1];
        if(x1 - x > y){
            cout << -1 << endl;
            return;
        }
        ans += (x1 - x) * y - (x1 - x) * (x1 - x + 1) / 2;
        y1 += y - (x1 - x);
    }
    auto [x,y] = p[m];
    if(y != n - x + 1){
        cout << -1 << endl;
    }else{
        ans += y * (y - 1) / 2;
        cout << ans << endl;
    }
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