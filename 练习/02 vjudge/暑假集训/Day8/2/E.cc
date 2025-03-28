#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
string s;
void solve(){
    int n;cin >> n;
    cin >> s;
    map<char,int> mp;
    int cnt = 0,M = 0;
    for(int i=0;i<n;i++){
        mp[s[i]] ++;M = max(M,mp[s[i]]);
    }
    if(n & 1 || M > n / 2){
        cout << -1 << endl;
        return;
    }
    M = 0;mp.clear();
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-i-1]) continue;
        cnt ++;mp[s[i]] ++;
        M = max(M,mp[s[i]]);
    }
    cout << max(cnt+1>>1,M) << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}