#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int n;string s;
    cin >> n >> s;
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '(') cnt ++;
        else cnt --;
        if(cnt < 0 || cnt == 0 && s[i] == '(') ans ++;
    }
    if(cnt) cout << -1 << endl;
    else cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}