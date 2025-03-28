#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve(){
    int n;cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        if(s.size() != 5 || s[2] != s[4]) continue;
        set<char> S;
        for(int i=0;i<4;i++) S.insert(s[i]);
        if(S.size() != 4) continue;
        ans ++; 
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}