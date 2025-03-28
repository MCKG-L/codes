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
int n;
map<int,int> mp;
int get(int x){
    int ans = 0;
    int y = 1ll & x;
    ans += y;
    for(int i=1;i<=63;i++){
        y = ((x>>(i-1)&1)&y)^(x>>i&1);
        if(y) ans += 1ll << i;
    }
    return ans;
}
void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        int t = get(a[i]);
        if(mp.count(t)){
            cout << mp[t] << ' ' << i << endl;
            return;
        }
        mp[a[i]] = i;
    }
}
signed main()
{
    IOS;int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
