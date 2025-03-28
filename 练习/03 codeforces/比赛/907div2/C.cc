#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int ans = 0,sum = 0;
    for(int r=n-1,l=0;r>=0;r--){
        if(l == r){
            if(a[l] == 1) ans ++;
            else ans += ceil(a[l]/2.0) + 1;
            break;
        }
        while(l < r && sum < a[r]){
            sum += a[l];
            a[l] = 0;l ++;
        }
        if(sum < a[r]){
            ans += ceil((sum+a[r])/2.0)+1;
            break;
        }
        if(sum > a[r]){
            l --;a[l] = sum - a[r];
        }
        ans += a[r] + 1;
        sum = 0;
        if(l == r) break;
    }
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