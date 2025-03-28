#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    map<int,int> mp;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]] = i;
    }
    set<int> s;
    int ans = 0;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
        if(mp[a[i]] == i) ans += s.size();
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}