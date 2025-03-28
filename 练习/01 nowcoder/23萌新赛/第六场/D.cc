#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
void solve(){
    int n,m;cin >> n >> m;
    int ans = 0;
    n -= m;
    while(m != 1){
        ans ++;
        m = (int)ceil(m*1.0/2);
        n -= m;
    }
    ans += n;
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
