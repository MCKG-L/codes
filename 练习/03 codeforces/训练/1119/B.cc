#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,M = 5e5 + 10;

void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    int M = -1,m = 1e9;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        M = max(M,a[i]);
        m = min(m,a[i]);
        a[i] += a[i-1];
    }
    map<int,int> mp;
    int t = n;
    for(int i=2;i<=t/i;i++){
        if(t % i == 0){
            mp[i] ++;
            if(i != t / i) mp[t/i] ++;
        }
    }
    int ans = M - m;
    for(auto [x,t] : mp){
        int M = -1,m = 1e18;
        for(int i=0;i<n/x;i++){
            int p = (i + 1) * x;
            int k = a[p] - a[p-x];
            M = max(M,k),m = min(m,k);
        }
        ans = max(ans,M - m);
    }
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}