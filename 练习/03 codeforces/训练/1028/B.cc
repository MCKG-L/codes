#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int N = 2e5 + 10;
typedef pair<int,int> PII;

void solve(){
    int n;cin >> n;
    vector<int> f(n+1),a(n+1);
    stack<int> stk;
    for(int i=1;i<=n;i++) cin >> a[i];
    int ans = 0;
    for(int i=1;i<=n;i++){
        int x = a[i];
        while(stk.size() && a[stk.top()] >= x) stk.pop();
        if(stk.size()){
            int k = stk.top();
            f[i] = f[k] + (i-k)*x;
        }else f[i] = i * x;
        stk.push(i);
    }
    for(int i=1;i<=n;i++) ans = max(ans,f[i]);
    cout << ans << endl;
}
signed main()
{
    IOS;
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}