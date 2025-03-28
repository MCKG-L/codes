#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    int m = 1e6,M = 1e6;
    vector<bool> st(m + 10);
    vector<int> primes,mp(M + 10),p(M+10);//p存每个数的最小质因子
    for(int i=2;i<=m;i++){
        if(!st[i]) primes.push_back(i),p[i] = i;
        for(int j=0;i*primes[j]<=m;j++){
            st[i*primes[j]] = 1;
            p[i*primes[j]] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
    for(int i=1;i<=n;i++){
        int x = a[i];
        while(p[x]){
            int temp = p[x];
            bool f = 0;
            while(x % temp == 0){
                x /= temp;f = 1;
            }
            if(f) mp[temp] ++;
        }
    }
    int ans = 0;
    for(int i=2;i<=M;i++){
        if(mp[i] > mp[ans]) ans = i;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}