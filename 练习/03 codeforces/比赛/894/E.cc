#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int n,m,d;
    cin >> n >> m >> d;
    int sum = 0,ans = 0;
    multiset<int> s;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        if(x < 0) continue;
        s.insert(x);sum += x;
        if(s.size() > m){
            sum -= *s.begin();
            s.erase(s.begin());
        }
        ans = max(ans,sum-d*i);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}