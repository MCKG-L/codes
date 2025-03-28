#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int l[N],r[N];
int n;
void solve(){
    string op;cin >> op;
    n = op.size();
    op = '!' + op;
    for(int i=n;i>=1;i--){
        r[i] = r[i+1];
        if(op[i] == 'p') r[i] ++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(op[i] == 'o') ans += r[i];
    }
    cout << ans << endl;
}
signed main()
{
    int t = 1;
    // cin >> t;
    while(t--) solve();
}