#include <bits/stdc++.h>
using namespace std;
void solve(){
    int k;cin >> k;
    int ans = 0,cnt = 0,i = 1;
    while(cnt <= k){
        ans += i*i;
        cnt += i;
        i++;
    }
    ans -= (i-1)*(cnt-k);
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}