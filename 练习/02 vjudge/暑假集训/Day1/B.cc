#include <iostream>
using namespace std;
void solve(){
    int n;cin >> n;
    int ans = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x == 0) cnt ++;
        else{
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    ans = max(ans,cnt);
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}