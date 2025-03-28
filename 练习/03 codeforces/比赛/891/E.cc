#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;
void solve(){
    int n;cin >> n;
    vector<PII> p(n+1);
    int sum = 0;
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        sum += x + 1;
        p[i] = {x,i};
    }
    sort(p.begin()+1,p.end());
    vector<int> ans(n+1);
    int t = 0;
    for(int i=1;i<=n;i++){
        auto [x,y] = p[i];
        sum -= (n-i-i+2) * (x-t);
        t = x;
        ans[y] = sum;
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main()
{
    IOS;int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}