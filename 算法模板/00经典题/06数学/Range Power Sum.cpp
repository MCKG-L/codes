#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e5 + 10,mod = 998244353,inf = 1e18;
/*abc_399_f
求所有子区间和的K次幂的和，最后结果取模
二项式展开
*/
void solve(){
    int n,k;
    cin >> n >> k;
    vector<array<int,15>> sum(n + 1,array<int,15>());
    vector<int> fac(k + 1),infac(k + 1),a(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];;
        a[i] = (a[i-1] + a[i]) % mod;
    }
    auto qmi = [&](int a,int b)->int{
        int ans = 1LL;
        while(b){
            if(b & 0x1) ans = ans * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return ans;
    };
    fac[0] = infac[0] = 1;
    for(int i=1;i<=k;i++){
        fac[i] = fac[i-1] * i % mod;
        infac[i] = infac[i-1] * qmi(i,mod-2) % mod;
    }
    for(int i=0;i<=n;i++){
        sum[i][0] = 1;
        for(int j=1;j<=k;j++){
            sum[i][j] = sum[i][j-1] * a[i] % mod;
        }
    }
    auto C = [&](int a,int b)->int{
        return fac[a] * infac[b] % mod * infac[a-b] % mod;
    };
    int ans = 0;
    for(int i=0;i<=k;i++){
        int s1 = 0,s2 = 0;
        for(int r=1;r<=n;r++){
            if(k-i & 0x1){
                s2 = (s2 - sum[r-1][k-i] + mod) % mod;
            }else{
                s2 = (s2 + sum[r-1][k-i]) % mod;
            }
            s1 = (s1 + s2 * sum[r][i] % mod) % mod;
        }
        ans = (ans + C(k,i) * s1) % mod;
    }
    cout << (ans + mod) % mod << endl;
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