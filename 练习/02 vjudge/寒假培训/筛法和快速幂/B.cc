#include <bits/stdc++.h>
using namespace std;
int solve(int a,int k,int p){
    int ans = 1;
    while(k){
        if(k & 1) ans = (long long)ans * a % p;
        k >>= 1;
        a = (long long)a * a % p;
    }
    return ans;
}
int main()
{
    int a,b,p;
    cin >> a >> b >> p;
    int ans = solve(a,b,p);
    cout << a << "^" << b << " mod " << p << "=" << ans;
    return 0;
}