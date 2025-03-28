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
    vector<int> a(n+1),b(n+1),c;
    for(int i=2;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    c = a;
    a[1] = 1;
    int cnt = 0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=1,j=1;i<=n&&j<=n;i++){
        while(j <= n && b[j] <= a[i]) j ++,cnt ++;
        j ++;
    }
    auto check = [&](int x) -> int {
        a = c;a[1] = x;
        sort(a.begin(),a.end());
        int res = 0;
        for(int i=1,j=1;j<=n&&i<=n;i++,j++){
            while(j <= n && b[j] <= a[i]) j ++,res ++;
        }
        return res;
    };
    int l = 1,r = m;
    int k = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid) == cnt) k = max(k,mid),l = mid + 1;
        else r = mid - 1;
    }
    // cout << "k:" << k << endl;
    int ans = cnt * k + (m-k)*(cnt+1);
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