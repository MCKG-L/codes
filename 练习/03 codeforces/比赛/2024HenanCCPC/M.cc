#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    int l = 0,r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        int M = 1e18,m = -1e18;
        for(int i=1;i<=n;i++){
            M = min(M,a[i] + mid * b[i]);
            m = max(m,a[i] - mid * b[i]);
        }
        if(M >= m){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << l << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}