#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 10;
typedef pair<int,int> PII;
int a[N],c[N];
int n,m,k;
bool check(int mid){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += max(0ll,a[i]-mid) * c[i];
    }
    if(cnt <= m) return 1;
    return 0;
}
void solve(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> a[i] >> c[i];
    int l = k,r = 1e5 + 10;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}