#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 3e5 + 10,M = 32,mod = 1e9 + 7,inf = 1e18;
/*
对于仅包含小写字母的长度为b的字符串，问：
同时包含a,b,c的字符串一共有多少种？
容斥原理：
所有： 26^n
不包含a：25^n
不包含b: 25^n
不包含c: 25^n
不包含ab:24^n
...
不包含abc:23^n
答案：26^n-(25^n+25^n+25^n-24^n-24^n-24^n+23^n)
*/
void solve(){
    int n;cin >> n;
    auto qmi = [&](int a,int b)->int{
        int res = 1ll;
        while(b){
            if(b & 0x1) res = res * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return res;
    };
    int ans = qmi(26,n)-(3*(qmi(25,n)%mod-qmi(24,n)%mod)%mod+qmi(23,n)%mod);
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;
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
