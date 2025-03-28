#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  3e5 + 10;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n+2),b(n+2);
    ll sum = 0;
    ll inf = 1e18;
    a[0] = a[n+1] = inf;
    b[0] = b[n+1] = inf;    
    vector<int> d1(n+1),d2(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
        sum += a[i] + b[i];
    }
    for(int i=1;i<=n;i++){
        d1[i] = max(0ll,max(a[i]-a[i-1]+d1[i-1],a[i]-a[i+1])-m);
    }
    for(int i=n;i>=1;i--){
        d2[i] = max(0ll,max(a[i]-a[i+1]+d2[i+1],a[i]-a[i-1])-m);
    }
    ll Min = inf;
    for(int i=1;i<=n;i++){
        Min = min(Min,a[i]-max(d1[i],d2[i])+b[i]);
    }
    // cout << Min << endl;
    cout << sum - Min * n << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}