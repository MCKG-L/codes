#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 1e5 + 10,INF = 1e9;

void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1),b(n+1);
    for(int i=2;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    a[1] = 1;
    int cnt = 0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=1,j=1;i<=n&&j<=n;i++){
        while(j <= n && b[j] <= a[i]) j ++,cnt ++;
        j ++;
    }
    cout << cnt << endl;
}
signed main()
{
    IOS;
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}