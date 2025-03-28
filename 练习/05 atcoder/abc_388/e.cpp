#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef pair<int,int> PII;
using ll = long long;
const int N =  1e6 + 10,inf = 3e18;
void solve(){
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    auto check = [&](int x)->bool{
        for(int i=1;i<=x;i++){
            if(2 * a[i] > a[n-x+i]) return false;
        }
        return true;
    };
    int l = 0,r = n / 2;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T --) solve();
    return 0;
}