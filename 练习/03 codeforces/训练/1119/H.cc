#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    string s;cin >> s;
    int ans = 0;
    int p = 1;
    for(int i=0;i<s.size();i++){
        int x = s[i] - '0';
        if(x == 0) x = 10;
        ans += abs(x - p) + 1;
        p = x;
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