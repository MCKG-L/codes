#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int mod = 998244353ll,inf = 1e9;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = ' ' + s;
    vector<int> ans(n << 1 | 1),a(n + 1);
    int sum = 0;
    for(int i=1;i<=n;i++){
        a[i] = s[i] - '0';
        sum += i * a[i];
    }
    for(int i=0;i<n;i++){
        ans[i] = sum;
        sum -= (n-i)*a[n-i];
    }
    int len = 0;
    for(int i=0;i<n<<1;i++){
        ans[i+1] += ans[i] / 10;
        ans[i] %= 10;
        if(ans[i+1] > 0) len ++;
    }
    for(int i=len;i>=0;i--) cout << ans[i];
    cout << endl;
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