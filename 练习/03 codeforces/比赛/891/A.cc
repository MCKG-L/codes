#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        sum += x;
    }
    if(sum & 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}