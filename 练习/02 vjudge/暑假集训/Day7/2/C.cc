#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin >> n;
    map<int,int> mp;
    int s = 0;mp[0] = 1;
    int ans = -1;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        s = s ^ x;
        for(auto [x,y] : mp){
            ans = max(ans,s ^ x);
        }
        mp[s] ++;
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}