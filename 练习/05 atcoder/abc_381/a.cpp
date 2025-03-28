#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10,inf = 1e18;
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    auto cal = [&](int st)->int{
        int ans = 0;
        int l = st,r = st;
        map<int,int> mp;
        while(r < n){
            if(a[r] != a[r+1]){
                while(l < r){
                    mp[a[l]] --;
                    l += 2;
                }
                l = r = r + 2;
            }else{
                mp[a[r]] ++;
                while(mp[a[r]] > 1){
                    mp[a[l]] --;l += 2;
                }
                r += 2;
            }
            ans = max(ans,r - l);
        }
        return ans;
    };
    cout << max(cal(1),cal(2)) << endl;
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