#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
/*
情形3：a,b的范围极大，询问的次数极小,但是模数的范围很小
b <= a <= 10^18 1 <= p <= 10^5
卢卡斯定理(lucas)：C(a,b) === C(a mod p, b mod p) * C(a / p, b / p) (mod p)
这里保证p是质数,所以可以使用费马小定理，利用快速幂求乘法逆元
*/
int p;
int qmi(int a,int k){
    int ans = 1;
    while(k){
        if(k & 1) ans = (ll)ans * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return ans;
}
int C(int a,int b){
    int ans = 1;
    //按照定义求组合数，按照这样写求解过程中不会出现小数
    for(int i=1,j=a;i<=b;i++,j--){
        ans = (ll)ans * j % p;
        ans = (ll)ans * qmi(i,p-2) % p;
    }
    return ans;
}
int lucas(ll a,ll b){
    if(a < p && b < p) return C(a,b);
    return (ll)C(a % p,b % p) * lucas(a / p,b / p) % p;
}
// bool is_prime(int n){
//     if(n < 2) return false;
//     for(int i=2;i<=n/i;i++){
//         if(n % i == 0) return false;
//     }
//     return true;
// }
int main()
{
    int n;cin >> n;
    while(n--){
        ll a,b;
        cin >> a >> b >> p;
        int ans = lucas(a,b);
        cout << ans << endl;
    }
    //100003、99991都是质数
    // cout << is_prime(99991) << endl;
    return 0;
}