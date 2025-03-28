#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
void solve(){
    set<int> s;
    for(int i=0;i<3;i++){
        int x;cin >> x;
        s.insert(x);
    }
    cout << *prev(s.rbegin()) << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}