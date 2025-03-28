#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
char s[N];
int n,k;
void solve(){
    cin >> n >> k;
    cin >> s;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'W') continue;
        ans ++;
        i += k - 1;
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