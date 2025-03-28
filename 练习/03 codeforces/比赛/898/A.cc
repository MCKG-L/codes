#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    string s = "abc";
    string x;cin >> x;
    int cnt = 0;
    for(int i=0;i<3;i++){
        if(s[i] != x[i]) cnt ++;
    }
    if(cnt < 3) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}