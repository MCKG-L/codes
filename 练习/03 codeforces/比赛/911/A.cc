#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10,M = 2 * N;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int cnt = 0,ans = 0;
    bool f = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '#'){
            ans += cnt;
            if(cnt > 2){
                f = 1;break;
            }
            cnt = 0;
        }else cnt ++;
    }
    if(cnt){
        if(cnt > 2) f = 1;
        ans += cnt;
    }
    if(f) cout << 2 << endl;
    else cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}