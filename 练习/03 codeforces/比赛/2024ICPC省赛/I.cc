#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
void solve(){
    int n;cin >> n;
    string s,t;
    cin >> s >> t;
    if(n < 2){
        cout << 0 << ' ' << 0 << endl;
        return;
    }
    ll cnt = 0,ans = 0;
    if(t[0] == t[1]){
        for(auto x : s) if(x != t[0]) cnt ++;
        cout << 1LL * n * (n - 1) / 2 << ' ' << cnt << endl;
    }else{
        string ss = s.substr(0,n / 2);
        for(auto x : ss) if(x != t[0]) cnt ++;
        ss = (n % 2 == 0 ? s.substr(n/2) : s.substr(n/2+1));
        for(auto x : ss) if(x != t[1]) cnt ++;
        if(n % 2 == 1 && s[n/2] != t[0] && s[n/2] != t[1]) cnt ++;
        cout << 1LL * (n / 2) * ((n + 1) / 2) << ' ' << cnt << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}