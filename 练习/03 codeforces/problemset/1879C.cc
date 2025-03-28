#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int mod = 998244353;
void solve(){
    string s;cin >> s;
    int n = s.size();
    int cnt = 0,ans = 1;
    for(int i=0;i<n;i++){
        int j = i + 1;
        while(j < n && s[j] == s[i]){
            j ++;
        }
        cnt ++;
        ans = (ans * (j-i)) % mod;
        i = j - 1;
    }
    for(int i=1;i<=n-cnt;i++){
        ans = (ans * i) % mod;
    }
    cout << n - cnt << ' ' << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}