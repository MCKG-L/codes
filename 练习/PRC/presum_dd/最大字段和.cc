#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    int ans = -0x3f3f3f,s = 0;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        s = max(s+x,x);
        ans = max(ans,s);
    }
    cout << ans;
    return 0;
}