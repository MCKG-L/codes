#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n,k;
bool check(int mid){
    int f = a[0];
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] - f > mid){
            cnt ++;
            f = a[i];
        }
    }
    if(cnt >= k) return 0;
    return 1;
}
void solve(){
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int l = 0,r = 1e9;
    int ans = 1e9;
    while(l <= r){
        int mid =(l*1ll + r) >> 1;
        if(check(mid)) ans = min(ans,mid),r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}