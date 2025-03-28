#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10,M = 60;
using ll = long long;
ll p[100];
bool insert(ll x){
    for(int i=M;i>=0;i--){
        if(x >> i & 0x1LL){
            if(p[i] == 0){
                p[i] = x;
                return true;
            }
            x ^= p[i];
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin >> n;
    for(int i=0;i<n;i++){
        ll x;cin >> x;
        insert(x);
    }
    ll ans = 0;
    for(int i=M;i>=0;i--) ans = max(ans,ans^p[i]);
    cout << ans << endl;
    return 0;
}