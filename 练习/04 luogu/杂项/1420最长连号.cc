#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,mask;cin >> n;
    int ans = 1,cnt = 1;
    cin >> mask;
    for(int i=1;i<n;i++){
        cin >> x;
        if(x == ++mask){
            cnt++;
            ans = max(ans,cnt);
        }else{
            mask = x;
            // ans = max(ans,cnt);
            cnt = 1;
        }
    }
    cout << ans;
    return 0;
}