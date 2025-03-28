#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
char s[10][10];
void solve(){
    for(int i=0;i<8;i++) cin >> s[i];
    string ans;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(s[i][j] == '.') continue;
            ans += s[i][j];
        }
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}