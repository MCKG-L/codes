#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve(){
    int n;cin >> n;
    vector<int> w(n+10);
    for(int i=1;i<=n;i++) cin >> w[i];
    vector<int> q(n+10);
    int hh = 0,tt = -1;
    for(int i=1;i<=n;i++){
        while(hh <= tt && w[q[tt]] >= w[i]) tt --;
        q[++tt] = i;
    }
    int ans = 0,tot = 0;
    while(hh <= tt){
        int k = q[hh ++];
        int cnt = (k - tot) / w[k];
        ans += cnt;
        tot += cnt * w[k];
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