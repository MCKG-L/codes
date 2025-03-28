#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
using i128 = __int128;
const int N = 2e5 + 10, mod = 998244353ll,inf = 1e18;
void solve(){
    vector<int> p;
    p.reserve(1e6);
    int cnt = 0;
    auto gePrimes = [&](int n)->void{
        vector<bool> st(2e6 + 10);
        for(int i=2;i<=n;i++){
            if(!st[i]) p.push_back(i),cnt ++;
            for(int j=0;p[j]<=n/i;j++){
                st[p[j] * i] = 1;
                if(i % p[j] == 0) break;
            }
        }
    };
    gePrimes(2e6);
    int n;cin >> n;
    int ans = 0;
    n = (i128)n;
    for(auto x : p){
        if((i128)pow(x,8) <= n) ans ++;
        else break;
    }
    for(int i=0;i<cnt;i++){
        if(p[i] * p[i] > n) break;
        int l = i + 1,r = cnt - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(p[mid] * p[mid] <= n / (p[i] * p[i])) l = mid + 1;
            else r = mid - 1;
        }
        ans += (r - i);
    }
    cout << ans << endl;
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