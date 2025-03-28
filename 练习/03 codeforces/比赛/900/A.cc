#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    map<int,int> mp;
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        mp[x] ++;
    }
    if(mp.count(k)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}