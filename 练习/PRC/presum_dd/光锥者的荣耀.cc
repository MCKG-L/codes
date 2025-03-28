#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n,k;
    cin >> n >> k;
    ll a[n+1] = {};
    for(int i=1;i<n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    ll max_n = -0x3f3f3f;
    for(int i=1;i<=n-k;i++){
        ll x = a[i+k-1] - a[i-1];
        max_n = max(max_n,x);
    }
    if(k == 0){
        cout << a[n-1];
    }else if(k >= n - 1){
        cout << 0;
    }else{
        cout << a[n-1] - max_n;
    }
    return 0;
}