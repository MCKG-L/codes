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
const int N = 1e5 + 10,mod = 1e9 + 7;
int n,k;
int fac[N],infac[N];
map<int,int> mp;
int qmi(int a,int b,int p){
    int ans = 1;
    while(b){
        if(b & 1) ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
int C(int a,int b){
    if(a < 0 || b < 0 || a < b) return 0;
    return fac[a] * infac[b] % mod * infac[a-b] % mod;
}
void solve(){

    cin >> n >> k;
    mp.clear();
    int l = -1;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        if(mp.count(x)) l = i - mp[x] - 1;
        mp[x] = i;
    }
    if(l == -1){
        cout << C(n,k) << endl;
        return;
    }
    if(k == 1){
        cout << (l == -1 ? n : n-1) << endl;
        return;
    }
    int ans = 0;
    ans += C(n-2,k);ans %= mod;
    for(int i=1;i<=l;i++){
        ans += 2*C(l,i)*C(n-l-2,k-1-i)%mod;
    }
    ans += C(n-l-2,k-1);ans %= mod;
    ans += C(n-2,k-2);ans %= mod;
    cout << ans << endl;
}
signed main()
{
    IOS;int t = 1;
    fac[0] = infac[0] = 1;
    for(int i=1;i<N;i++){
        fac[i] = fac[i-1] * i % mod;
        infac[i] = infac[i-1] * qmi(i,mod-2,mod) % mod;
    }
    cin >> t;
    while(t--) solve();
    return 0;
}
