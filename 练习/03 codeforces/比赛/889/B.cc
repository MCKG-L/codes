#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n;cin >> n;
    vector<set<int>> s(n);
    int ans = -1;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int m;cin >> m;
        while(m--){
            int x;cin >> x;
            mp[x] ++;
            s[i].insert(x);
        }
    }
    for(auto [x,y] : mp){
        map<int,int> st;
        for(auto ss : s){
            if(ss.find(x) == ss.end()){
                for(auto i : ss) st[i] ++;
            }
        }
        ans = max(ans,(int)st.size());
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