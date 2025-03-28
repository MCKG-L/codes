#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 1e5 + 10;
void solve(){
    int n;cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    if(n % 2) cout << -1 << endl;
    else{
        for(int i=0;i<n;i++){
            if(i % 2) cout << i << ' ';
            else cout << n - i << ' ';
        }
        cout << endl;
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}