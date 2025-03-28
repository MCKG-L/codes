#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void  solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1),b;
    for(int i=1;i<=n;i++) cin >> a[i];
    auto get = [&](int x,int k) -> int {
        int cnt = 0;
        for(int i=1;i<=n;i++){
            int d = b[i] >> x & 0x1;
            if(d == 0){
                cnt += (1ll << x) - (((1ll << x + 1) - 1ll) & b[i]);
                if(cnt > k) return cnt;
            }
        }
        return cnt;
    };
    auto find = [&](int k) -> int {
        b = a;
        int ans = 0;
        for(int i=60;i>=0;i--){
            int cnt = get(i,k);       
            if(cnt <= k){
                k -= cnt;
                ans |= (1ll << i);
                for(int j=1;j<=n;j++){
                   if((b[j] >> i & 0x1) == 0){
                        b[j] |= (1ll << i);
                        b[j] &= (1ll << i);
                   }
                }
            }
        }
        return ans;
    };
    for(int i=0;i<q;i++){
        int k;cin >> k;
        cout << find(k) << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}