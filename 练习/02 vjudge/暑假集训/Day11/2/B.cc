#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

void solve(){
    set<int> s;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        char c;cin >> c;
        s.insert(c-'a');
    }
    cout << *prev(s.end()) + 1 << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}