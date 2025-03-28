#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];sum += a[i];
    }
    // cout << max(m,sum) << endl;
    // if(sum >= m) cout << min(sum,m) << endl;
    // else{
    //     cout << sum << endl;
    // }
    cout << min(sum,m) << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}