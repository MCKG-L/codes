#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    map<string,int> mp;
    for(int i=0;i<n;i++){
        string s;cin >> s;
        mp[s] ++;
    }
    cout << mp.size() << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}