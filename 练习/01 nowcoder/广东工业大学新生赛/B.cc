#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<bool> st(n+1);
    int ans = 0;
    vector<int> cnt(n+1);
    while(m--){
        int x;string op;
        cin >> x >> op;
        if(op == "AC") st[x] = 1;
        else if(!st[x]) cnt[x] ++;
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(st[i]) ans += cnt[i],res ++;
    }
    cout << res << ' ' << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}