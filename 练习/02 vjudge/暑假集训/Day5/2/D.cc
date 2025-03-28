#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int a[N],n;
bool check(int k){
    int cnt = 0;
    int f = a[0];
    for(int i=1;i<n;i++){
        if((a[i]-f)>2*k){
            f = a[i];
            cnt ++;
        }
        if(cnt >= 3) return 0;
    }
    return 1;
}
void solve(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int l = 0,r = 1e9;
    while(l < r){
        int mid = (r-l)/2+l;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--) solve();
    return 0;
}