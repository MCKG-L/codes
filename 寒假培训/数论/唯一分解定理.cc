#include <iostream>
#include <map>
using namespace std;
/*
唯一分解定理：
每一个整数都可以分解为n个质数的乘积，并且是唯一的
求一个整数的所有因子个数
先分解质因数 再按公式计算所有因子个数
*/
map<int,int> mp;
void divide(int n){
    for(int i=2;i<=n;i++){
        while(n % i == 0){
            mp[i]++;
            n /= i;
        }
    }
}
int main()
{
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        divide(x);
    }
    // divide(n);
    long long ans = 1;
    for(auto it=mp.begin();it!=mp.end();it++){
        // cout << it->first << ": " << it->second << endl;
        ans *= (it->second + 1);
        ans %= 1000000007;
    }
    cout << ans;
    return 0;
}