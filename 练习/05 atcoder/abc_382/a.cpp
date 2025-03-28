#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
void solve(){
    int n,m;     
    cin >> n >> m;
    vector<int> a(n + 1),b(m + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=m;i++) cin >> b[i];
    map<int,int> mp;
    vector<int> alls;
    a[0] = inf;int now = inf;
    for(int i=1;i<=n;i++){
        if(a[i] >= now) continue;
        alls.push_back(a[i]);
        mp[a[i]] = i;
        now = a[i];
    }
    alls.push_back(-inf);
    for(int i=1;i<=m;i++){
        int x = b[i],l = 0,r = alls.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(alls[mid] <= x) r = mid - 1;
            else l = mid + 1;
        }
        cout << (alls[l] == -inf ? -1 : mp[alls[l]]) << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}