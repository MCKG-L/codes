#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void  solve(){
    int n;cin >> n;
    vector<int> a(n+1),p;
    for(int i=1;i<=n;i++) cin >> a[i];
    p.push_back(0);
    int s = 0;
    for(int i=n;i>=1;i--){
        s += a[i];
        p.back() += a[i];
        if(i > 1 && s >= 0) p.push_back(0);
    }
    reverse(p.begin(),p.end());
    int ans = 0;
    for(int i=0;i<p.size();i++){
        ans += (i + 1) * p[i];
    }
    cout << ans << endl;
}
signed main()
{
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}