#include <iostream>
using namespace std;
/*
情形2：a,b的范围很大，询问次数不太大
b <= a <= 1e5
预处理出阶乘fac[i]及其逆元infac[i]
除法取模很麻烦，需要用到逆元
C(a,b) = fac[a] * infac[b-a] * infac[b];
*/
typedef long long ll;
const int N = 100010,mod = 1e9 + 7;
int fac[N],infac[N];
//快速幂求逆元 a一定与mod互质，所以可以用费马小定理
/*
ax === 1 (mod p) 若a与互质,则a^p-1===1 (mod p) a*a^p-2 === 1 (mod p)
则a^p-2 % p 就是a模p的乘法逆元
*/
int qmi(int a,int k,int p){
    int ans = 1;
    while(k){
        if(k & 1) ans = (ll)ans * a % p;
        k >>= 1;
        a = (ll)a * a % mod;
    }
    return ans;
}
int main()
{
    fac[0] = infac[0] = 1;
    for(int i=1;i<N;i++){
        fac[i] = (ll)fac[i-1] * i % mod;
        infac[i] = (ll)infac[i-1] * qmi(i,mod-2,mod) % mod;
    }
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        int ans = (ll)fac[a] * infac[b] % mod * infac[a-b] % mod;
        cout << ans << endl;
    }
    return 0;
}