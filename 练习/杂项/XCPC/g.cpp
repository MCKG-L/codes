#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int N = 2e6 + 10,mod = 998244353,inf = 1e18;
/*2025ICPC-HeNan_G
求满足l<=a<=b<=r中，C(b,a)是奇数的个数
由卢卡斯定理:C(a,b) = C(a%2,b%2)*C(a/2,b/2)可知：在mod2的意义下
C(a,b)的值即为a、b的二进制表示中每一位的C(ai,bi)的乘积
而C(ai,bi)只能是下面四种情况：C(1,0)==1,C(0,0)==1,C(0,1)==0,C(1,1)==1
可以得到只要a & b == a，即a是b的子集时，满足C(b,a)为奇数
*/
void solve(){
    int l,r;
    cin >> l >> r;
    int ans = 0;
    for(int i=l;i<=r;i++){
        int s = 0,x = 0;
        int cnt = __builtin_popcount(i);
        ans += (1ll << cnt) - 1;//b的子集数目，不含0
        for(int k=log2(i);k>=0;k--){
            if(i >> k & 0x1){
                cnt --;
                if(s + (1ll << k) < l){
                    s += 1ll << k;
                    x += 1ll << cnt;
                }
            }
        }
        ans -= x;//小于l的子集数目
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}