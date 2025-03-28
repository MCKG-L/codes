#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int a[N];
int x[N];
int n;
void func(int x){
    for(int i=31;i>=0;i--){
        cout << ((x >> i & 1));
    }
    cout << endl;
}
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
        int p = 0;
        for(int i=l;i<=r;i++){
            p ^= a[i];
        }
        func(p);cout << "--" << endl;
        int ans = 0;
        // cout << t << endl;
        func(t);
        for(int i=0;i<31;i++){
            int d = t >> i & 1;
            // cout << d << "---" << endl;
            if(d == 0) ans += (1 << i);
        }
        // cout << ans % 8 << endl;
        // cout << ans << endl;
        func(ans);
    }
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
