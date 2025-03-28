#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,mod = 998244353;
int fac[N],infac[N];
int qmi(int a,int k){
    int ans = 1ll;
    while(k){
        if(k & 1) ans = ans * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int C(int a,int b){
    if(a < b) return 0;
    int ans = fac[a] * infac[b] % mod * infac[a-b] % mod;
    return ans;
}
void init(int n){
    fac[0] = infac[0] = 1;
    for(int i=1;i<=n;i++){
        fac[i] = fac[i-1] * i % mod;
        infac[i] = infac[i-1] * qmi(i,mod-2) % mod;
    }
}
void solve(){
    int n,m;
    cin >> n >> m;
    init(max(m,n));
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x == 0) continue;
        mp[x] ++;
    }
    for(int i=1;i<=m;i++){
        int ans = 1;
        bool f = 1;
        for(auto [x,y] : mp){
            if(x > i) {
                cout << 0 << endl;
                f = 0;
                break;
            }
            ans = (ans * qmi(C(i,x),y)) % mod;
        }
        if(f)
        cout << ans << endl;
    }
}
signed main()
{
    IOS;
    int T = 1;
    while(T--) solve();
    return 0;
}