#include <iostream>
using namespace std;
using ll = long long;
int main()
{
    int n,k;cin >> n >> k;
    ll a[n+1] = {};
    for(int i=2;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    if(k == 0){
        cout << a[n];
        return 0;
    }else if(k >= n - 1){
        cout << 0;
        return 0;
    }else{
        ll ans = -1;
        for(int i=1;i<=n-k;i++){
            ans = max(ans,a[i+k]-a[i]);
        }
        cout << a[n] - ans;
    }
    return 0;
}