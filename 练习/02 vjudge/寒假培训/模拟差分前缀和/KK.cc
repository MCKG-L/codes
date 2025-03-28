#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    int s = 0;
    int ans = -2e9;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(s+a[i] > a[i]){
            s += a[i];
        }else{
            s = a[i];
        }
        ans = max(ans,s);
    }
    cout << ans;
    return 0;
}