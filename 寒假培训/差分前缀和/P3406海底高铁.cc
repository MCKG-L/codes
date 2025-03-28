#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n,m,val;
    cin >> n >> m;
    ll a[n+2] = {};
    int p1,p2;
    cin >> p1;
    for(int i=2;i<=m;i++){
       cin >> p2;
       a[min(p1,p2)]++;
       a[max(p1,p2)]--;
       p1 = p2;
    }
    int A,B,C;
	ll ans=0;
    for(int i=1;i<=n-1;i++){
        a[i] += a[i-1];
        cin >> A >> B >> C;
        ans += min(a[i]*A,C+a[i]*B);
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}