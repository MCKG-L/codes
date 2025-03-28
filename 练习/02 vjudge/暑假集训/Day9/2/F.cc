#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int n,m;
multiset<int> p;
vector<pair<int,int>> d(N);
void solve(){
    cin >> n >> m;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        ans += x;
        p.insert(x);
    }
    for(int i=0;i<m;i++){
        int x;cin >> x;
        d[i].first = x;
    }
    for(int i=0;i<m;i++){
        int x;cin >> x;
        d[i].second = x;
    }
    sort(d.begin(),d.end(),[&](pair<int,int> p1,pair<int,int> p2){
        return p1.second > p2.second;
    });
    for(auto &[l,s] : d){
        auto pos = p.lower_bound(l);
        if(pos == p.end()) continue;
        p.erase(pos);
        ans -= s;
        if(p.size() == 0) break;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}