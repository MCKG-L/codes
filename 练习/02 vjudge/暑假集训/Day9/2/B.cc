#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
map<string,int> mp;
void solve(){
    vector<string> s;
    int n,m;cin >> n >> m;
    for(int i=0;i<n;i++){
        string c;cin >> c;
        s.push_back(c);
    }
    string c[m];
    for(int i=0;i<m;i++) cin >> c[i];
    int d[m],p;cin >> p;
    for(int i=0;i<m;i++){
        cin >> d[i];
        mp.insert({c[i],d[i]});
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(mp.count(s[i])) ans += mp[s[i]];
        else ans += p;
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