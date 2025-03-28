#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
void solve(){
    string s = "codeforces";
    int n;cin >> n;
    for(int i=0;i<n;i++){
        string a;cin >> a;
        int ans = 0;
        for(int i=0;i<10;i++){
            if(a[i] != s[i]) ans ++;
        }
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}