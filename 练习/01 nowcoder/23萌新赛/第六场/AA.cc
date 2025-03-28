#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int a[N];
int x[N];
int n;
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        x[i] = x[i-1] ^ a[i];
    }
    int m;cin >> m;
    while(m--){
        int l,r;cin >> l >> r;
        int t = x[r] ^ x[l-1];
        int ans = 0;
        for(int i=0;i<31;i++){
            int d = t >> i & 1;
            if((r-l+1) & 1){
                ans += (1 << i) * (!d);
            }
            
        }
        cout << ans << endl;
    }
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
