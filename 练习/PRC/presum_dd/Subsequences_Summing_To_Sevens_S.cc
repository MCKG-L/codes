#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;cin >> n;
    ll a[n+1] = {};
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
        a[i] %= 7;
    }
    int ans = -0x3f3f3f;
    for(int i=0;i<7;i++){
        int l = 0,r = n;
        while(l <= n && a[l]!=i) l++;
        while(r > 0 && a[r]!=i) r--;
        ans = max(ans,r-l);
    }
    cout << ans;
}