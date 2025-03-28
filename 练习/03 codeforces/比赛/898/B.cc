#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
void solve(){
    int n;cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a.push_back(x);
    }
    int ans = -1;
    for(int i=0;i<n;i++){
        int sum = 1;
        for(int j=0;j<n;j++){
            if(i == j) sum *= a[j] + 1;
            else sum *= a[j];
        }
        ans = max(ans,sum);
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