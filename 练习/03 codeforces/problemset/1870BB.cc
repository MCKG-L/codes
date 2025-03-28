#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    int k = 0,M = 0,mn = 0;
    for(int i=0;i<m;i++) k |= b[i];
    for(int i=0;i<n;i++) M ^= a[i],mn ^= a[i] | k;
    cout << min(M,mn) << ' ' << max(M,mn) << endl;
    // int M = 0,mn = 0;
    // for(int i=0;i<n;i++){
    //     cin >> a[i];
    //     M ^= a[i];
    // }
    // int k = 0;
    // for(int i=0;i<m;i++){
    //     cin >> b[i];
    //     k |= b[i];
    // }
    // for(int i=0;i<n;i++){
    //     a[i] |= k;
    //     mn ^= a[i];
    // }
    // cout << min(mn,M) << ' ' << max(mn,M) << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}