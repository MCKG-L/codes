// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int qmi(ll a,ll b,int p){
//     ll ans = 1;
//     while(b){
//         if(b & 1) ans = ans * a % p;
//         b >>= 1;
//         a = a * a % p;
//     }
//     return ans;
// }
// int main()
// {
//     int p;cin >> p;
//     ll ans = 1;
//     for(int i=2;i<=p-1;i++){
//         ans += qmi(i,p-2,p);
//     }
//     cout << ans;
// }
//p为素数
/*
for(int i=1;i<=p-1;i++){
    ans += qmi(i,p-2);
}
等价于: p*(p-1)/2
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long p;cin >> p;
    cout << p*(p-1)/2;
    return 0;
}