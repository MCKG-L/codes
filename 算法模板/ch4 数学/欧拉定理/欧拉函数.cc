/*
欧拉函数 F(n) 表示1~n中与n互质的数的个数
N = p1^a1 * p2^a2 * p3^a3 *...* pk^ak
则F(N) = N * (1-1/p1) * (1-1/p2) * ... * (1-1/pk)

证明：容斥原理
1、从1~N中去除p1,p2,p3...pk的所有倍数
2、加上所有pi*pj的倍数
3、减去所有pi*pj*pk的所有倍数
4、按照此规律进行下去
可以得到公式：F(N) = N * (1-1/p1) * (1-1/p2) * ... * (1-1/pk)

*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;cin >> n;
    while(n--){
        int a;cin >> a;
        int ans = a;
        for(int i=2;i<=a/i;i++){
            if(a % i == 0){
                ans = ans / i * (i - 1);
                while(a % i == 0) a /= i;
            }
        }
        if(a > 1) ans = ans / a * (a - 1);
        cout << ans << endl;
    }
    return 0;
}