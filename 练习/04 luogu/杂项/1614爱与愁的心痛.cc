#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int ans = 1e9,a[n]={};
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<=n-m;i++){
        int sum = 0;
        for(int j=i;j<=i+m-1;j++){
            sum += a[j];
        }
        ans = min(ans,sum);
    }
    if(m == 0 || n == 0) ans = 0;
    cout << ans;
    return 0;
}