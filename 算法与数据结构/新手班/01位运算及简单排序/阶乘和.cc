#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
显然算法是分优劣的
f1算法比较耗时
f2算法更加高效
*/
ll fac(int n){
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans *= i;
    }
    return ans;
}
ll f1(int n){
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans += fac(i);
    }
    return ans;
}

ll f2(int n){
    ll ans = 0;
    ll cur = 1;
    for(int i=1;i<=n;i++){
        cur *=  i;
        ans += cur;
    }
    return ans;
}
int main()
{
    int n;cin >> n;
    clock_t t1,t2;
    // t1 = clock();
    cout << f1(n);
    // t2 = clock();
    // cout << "time : " << double(t2 - t1)/CLOCKS_PER_SEC << "s";
    cout << endl;
    // t1 = clock();
    cout << f2(n);
    // t2 = clock();
    // cout << "time : " << double(t2 - t1)/CLOCKS_PER_SEC << "s";
    return 0;
}