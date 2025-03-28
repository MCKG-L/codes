#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 3e18;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    auto check = [&](int x)->bool{
        int res = 0;
        for(int i=1;i<=n;i++){
            int t = (x + a[i]) / (2LL * a[i]);
            if(t > 1e9) return false;
            int cost = t * t * a[i];
            if(res + cost < res || res + cost > m) return false;
            res += cost;
        }
        return res <= m;
    };
    int l = 0,r = m;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    int ans = 0,res = 0;
    vector<int> nd(n+1);
    for(int i=1;i<=n;i++){
        int u = (r + a[i]) / (2 * a[i]);
        ans += u;
        m -= u * u * a[i];
        nd[i] = (2 * u + 1) * a[i];
    }
    sort(nd.begin()+1,nd.begin()+1+n);
    for(int i=1;i<=n;i++){
        if(m >= nd[i]){
            ans ++;
            m -= nd[i];
        }else break;
    }
    cout << ans << endl;
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