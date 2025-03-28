#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
/*
本题题意：给定n个1和n个0，将这些0和1排列成一个序列
求满足任意前缀中0的个数不小于1的个数的序列种数

卡特兰数：上述题意就是卡特兰数的标准含义，满足的序列种数称为卡特兰数
C(2n,n)-C(2n,n-1) = C(2n,n)/(n+1)
C(2n,n)/(n+1)就是卡特兰数

例如进栈出栈问题可以应用卡特兰数
*/
const int p = 1e9 + 7;
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
    int a = 2 * n,b = n;
    int ans = 1;
    // for(int i=a,j=1;j<=b;i--,j++){
    //     ans = (ll)ans * i % p;
    //     ans = (ll)ans * qmi(j,p-2,p) % p;
    // }
    //或者
    for(int i=a;i>a-b;i--) ans = (ll)ans * i % p;
    for(int i=1;i<=b;i++) ans = (ll)ans * qmi(i,p-2,p) % p;
    ans = (ll)ans * qmi(n+1,p-2,p) % p;
    cout << ans << endl;
    return 0;
}