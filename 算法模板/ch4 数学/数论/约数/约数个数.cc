/*
唯一分解定理：任意一个正整数 可以分解为若干个质数的乘积 并且分解唯一
N = p1^a1 * p2^a2 * p3^a3 + ... + pn^an
约数个数：S = (a1+1)*(a2+1)*(a3+1)*...*(an+1)
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>
const int mod = 1e9 + 7;
using namespace std;
/*
求n个数的乘积 的约数个数
*/
unordered_map<int,int> mp;
void divide(int n){
    for(int i=2;i<=n/i;i++){
        while(n % i == 0){
            n /= i;
            mp[i]++;
        }
    }
    if(n > 1) mp[n]++;
}
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        divide(x);
    }
    long long ans = 1;
    for(pair<int,int> i : mp){
        ans = ans * (i.second + 1) % mod;
    }
    cout << ans << endl;
    return 0;
}