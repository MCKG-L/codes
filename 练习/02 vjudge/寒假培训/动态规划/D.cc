#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    vector<int> a(n+1);
    int ans = INT_MIN;
    int s = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        s = s > 0 ? s+a[i] : a[i];
        ans = max(ans,s);
    }
    cout << ans;
    return 0;
}
