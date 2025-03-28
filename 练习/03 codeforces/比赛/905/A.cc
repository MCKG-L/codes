#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int x = 1;
    string s;cin >> s;
    int ans = 0;
    for(int i=0;i<4;i++){
        int t = s[i] - '0';
        if(t == 0) t = 10;
        ans += abs(x-t)+1;
        x = t;
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