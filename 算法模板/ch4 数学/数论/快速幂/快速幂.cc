/*
快速求出 a^k%p 的值 时间复杂度：O(logk)
*/
#include <iostream>
using namespace std;
typedef long long ll;
ll qmi(ll a,ll k,ll p){
    ll ans = 1;
    while(k){
        if(k & 1) ans = ans * a % p;
        k >>= 1; 
        a = a * a % p;
    }
    return ans;
}
int main()
{
    int a,k,p;
    int ans = qmi(a,k,p);
}