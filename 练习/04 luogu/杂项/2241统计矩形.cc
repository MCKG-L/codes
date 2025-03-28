#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    long long ans1 = 0,ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans += min(i,j);
            ans1 += i * j;
        }
    }
    cout << ans << " " << ans1 - ans;
    return 0;
}