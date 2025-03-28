#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n,x;
bool check(int mid){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += max(0ll,mid-a[i]);
    }
    if(sum <= x) return 1;
    return 0;
}
void solve(){
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> a[i];
    int l = 1, r = 2e9;
    int ans = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = max(ans,mid),l = mid + 1;
        else r = mid - 1;
    }
    // cout << l << endl;
    cout << ans << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}