#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  2e5 + 10,inf = 1e18;
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1),pre(n + 1);
    string s;cin >> s;
    for(int i=0;i<n;i++){
        if(s[i] == '1') a[i + 1] = 1;
        else a[i+1] = 0;
        pre[i+1] = pre[i] + a[i+1];
    }
    vector<PII> p;
    // p.push_back({0,0});
    for(int i=1;i<=n;i++){
        if(a[i] == 0) continue;
        int j = i;
        while(j <= n && a[j] == 1){
            j ++;
        }
        p.push_back({i,j-1});
        i = j - 1;
    }
    if(p.size() == 0){
        cout << 0 << endl;
        return ;
    }
    // for(auto [l,r] : p) cerr << l << ' ' << r << endl;
    int ans = inf;
    vector<int> d1(n + 1,0);
    d1[p[0].first] = 0;
    for(int i=1;i<p.size();i++){
        auto [l,r] = p[i];
        auto [l1,r1] = p[i-1];
        d1[l] = d1[l1] + pre[l-1] * (l - r1 - 1);
    }
    auto [l1,r1] = p.back();
    ans = min(ans,d1[l1]+0ll);
    int sum = 0ll;
    for(int i=p.size()-2;i>=0;i--){
        auto [l,r] = p[i];
        auto [ll,rr] = p[i+1];
        sum += (pre[n] - pre[r]) * (ll - r - 1);
        ans = min(ans,sum+d1[l]);
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