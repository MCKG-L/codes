#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
        a[i] %= 7;
    }
    int ans = 0;
    for(int i=0;i<7;i++){
        int l = 0,r = 0;
        for(int k=0;k<=n;k++){
            if(a[k] == i){
                l = k;
                break;
            }
        }
        for(int k=n;k>=1;k--){
            if(a[k] == i){
                r = k;
                break;
            }
        }
        ans = max(ans,r-l);
    }
    cout << ans;
    return 0;
}