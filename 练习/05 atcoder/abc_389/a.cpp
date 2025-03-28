#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 1e18;
void solve(){
    int n;cin >> n;
    int ans = 0;
    auto check = [&](int x,int y)->bool{
        return (x + 0.5) * (x + 0.5) + (y + 0.5) * (y + 0.5) <= n * n;
    };
    for(int i=0;i<n;i++){
        int l = 0,r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(check(i,mid)) l = mid + 1;
            else r = mid - 1;
        }
        ans += 4 * r;
    }
    cout << ans + 1 << endl;
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