#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
using ll = long long;
typedef pair<int,int> PII;
void solve(){
    int n;
    cin >> n;
    int ma,mb;
    cin >> ma;
    vector<int> A(ma+1);
    for(int i=1;i<=ma;i++){
        cin >> A[ma-i+1];
    }
    cin >> mb;
    vector<int> B(ma+1);
    for(int i=1;i<=mb;i++){
        cin >> B[mb-i+1];
    }
    ll s = 1,ans = 0;
    n = max(ma,mb);
    for(int i=1;i<=n;i++){
        int k = max({A[i]+1,B[i]+1,2});
        ans = (ans + (A[i]-B[i])*s) % mod;
        s = (s * k) % mod;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}