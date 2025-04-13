#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
const int N = 2e5 + 10,mod = 1e9 + 7,inf = 1e18;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    int l,r;
    cin >> l >> r;
    // cerr << l << ' ' << r << endl;
    vector<int> pre(n + 1);
    for(int i=1;i<=n;i++) pre[i] = pre[i-1] + a[i];
    auto cal = [&](int x)->int{
        int k = (x - 1) / n + 1;
        int t = max(k-1,0ll);
        int ans = t*(1+t)/2*pre[n];
        t = x - t * n;
        cerr << t << endl;
        return ans + k * pre[t];
    };
    cout << cal(r) - cal(l-1) << endl;
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