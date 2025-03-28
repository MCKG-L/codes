#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
int a[N],b[N];
int n,m;
bool check(int mid){
    for(int i=1;i<=n-mid;i++){
        if(a[i] >= b[mid+i]) return 0;
    }
    return 1;
}
void solve(){
    cin >> n >> m;
    a[1] = 1;
    for(int i=2;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    sort(a+1,a+n+1),sort(b+1,b+1+n);
    int ans = n + 1;
    int l = 0,r = n;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = min(ans,mid),r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}