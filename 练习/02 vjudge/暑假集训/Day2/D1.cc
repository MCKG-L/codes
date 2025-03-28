#include <iostream>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;
void solve(){
    int n,q;cin >> n >> q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    while(q--){
        int l,r,k;
        cin >> l >> r >> k;
        int s = a[r] - a[l-1];
        if((a[n] - s + (r-l+1)*k) & 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}