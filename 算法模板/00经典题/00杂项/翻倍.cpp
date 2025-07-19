#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
using i128 = __int128;
typedef pair<int,int> PII;
using ll = long long;
const int mod = 1e9 + 7,inf = 1e18;
const int N = 5e5 + 10;
void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i=1;i<=n;i++) cin >> a[i];
    stack<PII> stk;
    int ans = 0;
    for(int i=n-1;i>=1;i--){
        int x = a[i];
        if(x <= a[i+1]){
            int t = 0;
            while(x * 2 <= a[i+1]){
                t += 1,x *= 2;
            }
            if(t > 0) stk.push({t,i});
        }else{
            int t = 0,s = a[i+1];
            while(x > s){
                t ++,s *= 2;
            }
            // cerr << "i : " << i << ' ' << t << endl;
            while(t > 0 && stk.size()){
                auto [k,pos] = stk.top();stk.pop();
                if(k >= t){
                    ans += (pos - i) * t;
                    if(k - t > 0) stk.push({k-t,pos});
                    t = 0;
                }else{
                    ans += k * (pos - i);
                    t -= k;
                }
            }
            if(t > 0) ans += (n - i) * t;
        }
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