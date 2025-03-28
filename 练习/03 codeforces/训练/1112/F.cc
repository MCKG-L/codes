#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 10010,M = 1e5 + 10;
void solve(){
    int T,m;
    cin >> T >> m;
    vector<int> p(m+10);
    p[0] = 1;
    for(int i=1;i<m;i++){
        p[i] = p[i-1] * i % m;
    }
    auto qmi = [&](int a,int k) -> int {
        int ans = 1ll;
        while(k){
            if(k & 1) ans = ans * a % m;
            k >>= 1;
            a = a * a % m;
        }
        return ans;
    };
    auto f = [&](int n) -> int {
        int ans = 1ll;
        while(n > m){
            int k = n / m;
            int r = n % m;
            ans = (ans * qmi(p[m-1],k) % m * p[r]) % m;
            n = k;
        }
        if(n == m) n = m - 1;
        ans = ans * p[n] % m;
        return ans;
    };
    while(T--){
        int n;cin >> n;
        cout << f(n) << endl;
    }
}
signed main()
{
    IOS;
	int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}