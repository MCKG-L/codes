#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
char s[N];
int n;
void solve(){
    cin >> s + 1;
    n = strlen(s + 1);
    int cnt = 0;
    bool f = 0;
    int sum = 0,ans = 0;
    int m = 1e9;
    for(int i=1;i<=n;i++){
        if(s[i] == 'A') cnt ++;
        else{
            if(cnt == 0) f = 1;
            sum += cnt;
            if(cnt > 0) m = min(m,cnt);
            cnt = 0;
        }
    }
    sum += cnt;
    if(cnt == 0) f = 1;
    if(cnt > 0) m = min(m,cnt);
    // for(auto i : p) cout << i << ' ';
    // cout << endl;
    if(f) ans = sum;
    else{
        ans = sum - m;
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