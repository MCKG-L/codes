#include <bits/stdc++.h>
// #define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e6 + 10;
int p[N],cnt;
bool st[N];
void get_primes(){
    int n = 1e3;
    for(int i=2;i<=n;i++){
        if(!st[i]) p[cnt ++] = i;
        for(int j=0;p[j]<=n/i;j++){
            st[p[j]*i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}
void solve(){
    int n;cin >> n;
    get_primes();
    vector<int> mp(N,0),a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        bool f = 0;
        for(int j=0;j<cnt;j++){
            if(a[i] % p[j] == 0){
                f = 1;mp[p[j]] ++;
            }
        }
        if(f == 0) mp[a[i]] ++;
    }
    int ans = -1,mx = -1;
    for(int i=2;i<N;i++){
        if(mp[i] > mx){
            mx = mp[i];
            ans = i;
        }
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