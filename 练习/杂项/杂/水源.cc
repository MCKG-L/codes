#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += a[i] * (n - i);
    }
    cout << ans;
    return 0;
}