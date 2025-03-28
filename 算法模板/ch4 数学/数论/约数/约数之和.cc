/*
N = p1^a1 * p2^a2 * p3^a3 + ... + pn^an

约数之和：S = (p1^0+p1^2+...+p1^a1)*(p2^0+p2^1+...+p2^a2)*....
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>
const int mod = 1e9 + 7;
using namespace std;
/*
求n个数的乘积 的约数之和
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
        int p = i.first,a = i.second;
        long long s = 1;
        //求等比数列 技巧
        for(int j=0;j<a;j++){
            s = (s * p + 1) % mod;
        }
        ans = ans * s % mod;
    }
    cout << ans << endl;
    return 0;
}