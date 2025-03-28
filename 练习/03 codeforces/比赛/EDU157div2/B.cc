#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef pair<int,int> PII;
const int N = 2e5 + 10;

void solve(){
    int n;cin >> n;
    vector<PII> ans;
    vector<int> a;
    for(int i=0;i<2*n;i++){
        int x;cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int sum = 0;
    for(int i=0;i<n;i++){
        ans.push_back({a[i],a[2*n-i-1]});
    }
    int x = ans[0].first,y = ans[0].second;
    for(int i=1;i<n;i++){
        auto [x1,y1] = ans[i];
        sum += abs(y1-y)+abs(x1-x);
        x = x1,y = y1;
    }
    cout << sum << endl;
    for(auto [x,y] : ans) cout << x << ' ' << y << endl;
}
signed main()
{
    IOS;
	int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}