#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
int cal(int x){
    if(x & 1) return (x-1)/2*x;
    return x/2*(x-1);
}
bool check(int mid,int n){
    // int x = mid * (mid-1)/2;
    if(cal(mid) >= n) return 1;
    return 0;
}
void solve(){
    int n;cin >> n;
    int l = 0,r = 2648956421;
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid,n)) r = mid;
        else l = mid + 1; 
    }
    if(cal(l) == n){
        cout << l << endl;
    }else{
        l --;
        int ans = l + n - cal(l);
        cout << ans << endl;
    }
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}