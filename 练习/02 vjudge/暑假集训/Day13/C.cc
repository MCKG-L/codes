#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
int n;
int cnt[N];
void solve(){
    memset(cnt,0,(n+2)*4);
    string s;cin >> s;
    n = s.size();
    s = " " + s;
    for(int i=n;i>=1;i--){
        cnt[i] = cnt[i+1];
        if(s[i] == '1') cnt[i] ++;
    }
    // for(int i=1;i<=n;i++){
    //     cout << cnt[i] << ' ';
    // }
    // cout << endl;
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == '0'){
            if(!cnt[i+1]) ans ++;
            break;
        }
        if(s[i] == '?' || s[i] == '1'){
            if(!cnt[i+1]) ans ++;
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;cin >> t;
    while(t--) solve();
    return 0;
}