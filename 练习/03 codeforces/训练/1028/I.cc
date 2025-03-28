#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n,m;cin >> n >> m;
    int ans = 0;
    while(m > 3 * n){
        ans ++;
        m -= n * 2;
    }
    int k = 1;
    for(int i=0;k<m;i++){
        k *= 3;
        ans ++;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}