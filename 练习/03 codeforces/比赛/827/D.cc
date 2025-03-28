#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;

void solve(){
    vector<int> a[1001];
    int n;cin >> n;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        a[x].push_back(i + 1);
    }
    for(int i=1;i<=1000;i++){
        if(a[i].size()) sort(a[i].begin(),a[i].end());
    }
    int ans = -1;
    for(int i=1;i<=1000;i++){
        if(a[i].size() == 0) continue;
        for(int j=1;j<=i;j++){
            if(a[j].size() == 0) continue;
            if(__gcd(i,j) != 1) continue;
            ans = max(ans,a[i].back() + a[j].back());
        }
    }
    if(a[1].size()) ans = max(ans,a[1].back() * 2);
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