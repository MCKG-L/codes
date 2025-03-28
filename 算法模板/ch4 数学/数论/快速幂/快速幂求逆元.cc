#include <iostream>
using namespace std;
typedef long long ll;
/*
若b 与 m互质,并且b是a的倍数，则存在一个x使得a/b === a*x(mod m),称x为b的模m乘法逆元
当 如果b 是 m的倍数，一定不存在逆元 b*x === 0 (mod m)
如果b与m互质，则b*x === 1 (mod m) 根据费马定理 b^m-1 === 1 (mod m) -> b*b^m-2 == 1 (mod m)
所以b^m-2 % m 就是b的模m乘法逆元
*/
int qmi(int a,int k,int p){
    int ans = 1;
    while(k){
        if(k & 1) ans = (ll)ans * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return ans;
}
int main()
{
    int n;cin >> n;
    while(n--){
        int a,p;
        cin >> a >> p;
        if(a % p) cout << qmi(a,p-2,p) << endl;
        else puts("impossible");
    }
    return 0;
}