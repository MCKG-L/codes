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
    map<int,int> mp;
    int M = 0;
    set<int> a;
    a.insert(0);
    for(int i=0;i<n;i++){
        int x;cin >> x;
        if(x == 0) continue;
        mp[x] ++;
        M ++;
        a.insert(x);
    }
    for(int i=1;i<=m;i++){
        int ans = 1;
        int cnt = 0,mn = 0;
        if(i < M){
            cout << 0 << endl;
            continue;
        }
        for(auto x : a){
            if(x == 0) continue;
            int sum = M - cnt;
            int k = x - mn;
            ans = (ans * qmi(C(i,sum),k)) % mod;
            cnt += mp[x];
            mn = x;
        }
        cout << ans << endl;
    }
}
signed main()
{
    IOS;init(N-1);
    int T = 1;
    while(T--) solve();
    return 0;
}