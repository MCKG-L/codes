#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;
void solve(){
    int n,k;cin >> n >> k;
    function<void(int)> dfs = [&](int x) -> void {
        if(x == 0) return;
        int r = x % k;
        x /= k;
        if(r < 0) r -= k,x ++;
        dfs(x);
        if(r >= 0 && r <= 9) cout << r;
        else{
            cout << (char)('A' + r - 10);
        }
    };
    cout << n << "=";
    dfs(n);
    cout << "(base" << k << ")" << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}