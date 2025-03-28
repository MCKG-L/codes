#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vector<int> cnt(30,0);
    for(auto i : s) cnt[i-'a'] ++;
    int mx = 0;
    for(auto i : cnt) mx = max(mx,i);
    if(n & 1){
        cout << max(1ll,2*mx-n) << endl;
    }else{
        cout << max(0ll,2*mx-n) << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}